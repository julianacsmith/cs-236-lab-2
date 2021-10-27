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
            att.push_back(rel.GetAttribute(i));
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