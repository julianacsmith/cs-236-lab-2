//
// Created by Juliana Smith on 10/25/21.
//

#include "Interpreter.h"
#include "Relation.h"
#include "Header.h"
#include "Tuple.h"
#include "Parser.h"


void Interpreter::SchemeToRelation() {
    vector<Predicate> schemes = datalogProgram.GetSchemes();
    for (Predicate scheme: schemes) { // Taking a look at all the schemes I have
        string name = scheme.GetName();
        vector<Parameter> sPara = scheme.GetParameter();
        vector<string> att;
        for(unsigned int i = 0; i < sPara.size(); i++){
            att.push_back(sPara.at(i).toString());
        }
        Header h = Header(att);
        database.AddRelation(Relation(name, h));
    }
}

void Interpreter::FactToTuple() {
    vector<Predicate> facts = datalogProgram.GetFacts();
    for (Predicate fact: facts){
        string name = fact.GetName();
        vector<Parameter> fPara = fact.GetParameter();
        Relation *r =  database.FindRelation(name);
        Tuple t = Tuple();
        for(unsigned int i = 0; i < fPara.size(); i++){
            t.SetValue(fPara.at(i).toString());
        }
        r->addTuple(t);
    }
}

Relation Interpreter::EvaluatePredicate(Relation* r, Predicate p) {
    vector<Parameter> fPara = p.GetParameter();
    vector<string> att;
    Relation rel = *r;
    variables.clear();
    vector <int> indicies;
    for(unsigned int i = 0; i < fPara.size(); i++){
        string currP = fPara.at(i).toString();
        if(fPara.at(i).isConst()){
            //perform select
            rel = rel.select(i, fPara.at(i).toString());
            rel.SetConst(true);
            int icomp = (signed)i;
            if(icomp < rel.GetHeader().Size() ) {
                att.push_back(rel.GetAttribute(i));
            } else {
                att.push_back(currP);
            }
        } else {
            map<string,int>::iterator it;
            it = variables.find(currP);
            att.push_back(currP);
            if(it != variables.end()){
                //perform select 2
                rel = rel.select(variables.at(currP),i);
            } else {
                variables.insert(std::pair<string, int>(currP, i));
                // keep for project
                // rename
            }
            rel = rel.rename(att);
        }
    }
    return rel;
}

Relation Interpreter::EvaluateQueries(){
    cout << "Query Evaluation" << endl;
    vector<Predicate> queries = datalogProgram.GetQueries();
    Relation *rel;
    Relation r;
    for(Predicate query : queries){
        string name = query.GetName();
        rel =  database.FindRelation(name);
        if(rel->GetName() != ""){
            r = EvaluatePredicate(rel, query);
            rel = &r;
            cout << QueryToString(query, rel);
        }
    }
    return r;
}

void Interpreter::EvaluateRules(){
    int counter = 0;
    cout << "Rule Evaluation" << endl;
    do {
        addedTuple = false;
        for (Rule rule : datalogProgram.GetRules()) {
            //string temp = rule.toString();
            //cout << temp << endl;
            //cout << temp << endl;
            Relation r = EvaluateRule(rule);
        }
        counter++;
    }while(addedTuple);
    cout << endl << "Schemes populated after " << counter << " passes through the Rules." << endl << endl;
}

Relation Interpreter::EvaluateRule(Rule r) {
    Relation *rel;
    vector<Relation> relations; // New Vector to contain all relations
    Relation finalRel; // Contains the final relation to union late
    for(Predicate p : r.GetBody()){ // for every predicate in the current rule
        string name = p.GetName(); // Get the name
        rel = database.FindRelation(name); // Find the matching relation in the database
        if(rel->GetName() != ""){ // As long as it exists
            Relation newRel = EvaluatePredicate(rel, p); // Make a new relation that evaluates the db relation
            relations.push_back(newRel); // Push back into relations vector
        }
    }
    vector<int> matches = FindMatches(r.GetBody()); // Find all the matches were supposed to have
    /**if(relations.size() == 1){ // If theres only one relation
        finalRel = relations.at(0); // Set final to equal that relation
    } else { // If more than one relation **/
        finalRel = relations.at(0);
        for (unsigned int i = 1; i < relations.size(); i++) { // For every relation in relations
            finalRel = finalRel.Join(relations.at(i), matches); // the 2 adjacent relations and save to finalRel
        }
    //}
    vector<string> attOfHeader; // Vector of strings to hold attributes we want to keep
    for(Parameter p : r.GetHead().GetParameter()){ // For every parameter in teh head of the rule
        attOfHeader.push_back(p.toString()); // Push it back into attOfHeader
    }
    vector<int> matchingPos = FindCols(attOfHeader, finalRel.GetHeader().GetAllAttributes()); // Find Cols that match between head and finalRel
    finalRel = finalRel.project(matchingPos);  // Project the columns we want
    rel = database.FindRelation(r.GetHead().GetName()); // Find the matching db relation we want to union
    finalRel.SetName(r.GetHead().GetName()); // Set finalRel's name to the rule's head's name
    finalRel = finalRel.rename(rel->GetHeader().GetAllAttributes()); // Rename finalRel so the union works
    Relation newRel = rel->Unity(finalRel, addedTuple); // UNION TIME
    //cout << RuleToString(r, &finalRel);
    rel->SetName(r.GetHead().GetName());
    return *rel;
}

string Interpreter::QueryToString(Predicate p, Relation* r) {
    string output = "";
    vector<Parameter> para = p.GetParameter();
    output += p.toString() + "? ";
    if(!r->IsEmpty()){
        output += "Yes(" + to_string(r->Size()) + ")\n";
        output += r->toString(variables);
    } else {
        output += "No\n";
    }
    return output;
}

string Interpreter::RuleToString(Rule rule, Relation* r) {
    /**string output = "";
    output += "  ";
    for (Tuple t: tuples) {
        //output += r->GetHeader().GetAttribute(i);
    }
    return output;**/
    string output = "";
    if(!r->IsEmpty()) {
        r->toString(variables);
    } else {
        output += "\n";
    }
    return output;
}

string Interpreter::TupleToString(Header h, set<Tuple> tuples) {
    string output = "";
    for(Tuple t : tuples){
        for(int i = 0; i < h.Size(); i++){
            output += h.GetAttribute(i);
            output += "=";
            output += t.GetValue(i);
            if(i != h.Size()-1){

            }
        }
    }
    return output;
}

std::vector<int> Interpreter::FindMatches(std::vector<Predicate> p) {
    vector<string> matches;
    vector<string> trueMatch;
    vector<string> temp;
    map<string, int> tracker;
    vector<int> positions;
    int j = 0;
    for(Predicate pred : p){ // For every predicate in p
        vector<Parameter> param = pred.GetParameter(); // Get the parameters
        for(Parameter pa : param){ // For every parameter in p.GetParameter()
            if(find(matches.begin(), matches.end(), pa.toString()) != matches.end()){ // See if the parameters exists in matches. If it does...
                string val = pa.toString(); // Save the parameter's toString
                trueMatch.push_back(pa.toString()); //
                positions.push_back(tracker.at(val));
                positions.push_back(j);
            }
            tracker.insert(std::pair<string, int>(pa.toString(), j));
            temp.push_back(pa.toString());
            j++;
        }
        if(matches.size() == 0){
            matches = temp;
        } else {
            matches = trueMatch;
        }
        temp.empty();
        j = 0;
    }
    return positions;
}

std::vector<int> Interpreter::FindCols(std::vector<std::string> att, std::vector<std::string> cols) {
    vector<int> positions; // Vector of ints
    for(string s : att){ // For every string in att
        for(unsigned int i = 0; i < cols.size(); i++){ // For every string in cols
            if(s == cols.at(i)){ // If s and cols.at(i) are matching
                positions.push_back(i); // Push back the col position
            }
        }
    }
    return positions; // return positions
}