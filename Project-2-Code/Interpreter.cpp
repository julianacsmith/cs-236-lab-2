//
// Created by Juliana Smith on 10/25/21.
//

#include "Interpreter.h"
#include "Relation.h"
#include "Header.h"
#include "Tuple.h"
#include "Parser.h"


void Interpreter::SchemeToRelation() {
    for (Predicate scheme: datalogProgram.GetSchemes()) { // Taking a look at all the schemes I have
        /**Header h = Header(); // Creating the header object
        string rName = scheme.substr(0, idx); // Making the name of the scheme

        for(int i = idx; i < idx2; i++) { // Cycle through the inside of the parenthesis
            if (scheme.at(i) == ',') { // If a comma, skip over it
                i++;
            } else { // Otherwise Add the attribute to the header
                h.AddAttribute(scheme.substr(i, i + 1));
            }
        }
        database.AddRelation(Relation(rName, h)); // Finally, create the new relation and push it into the vector of relations
    }
         **/
    }
}

void Interpreter::FactToTuple() {
    for (Predicate fact: datalogProgram.GetFacts()){
        /**string name = fact.substr(0, idx); // Gets the relation name - COULD GET RID OF DUE TO ASSUMPTIONS
        Tuple t = Tuple(); // Creates a new tuple
        if(database.FindRelation(name)){ // If the relation exists
            for(int i = idx; i < idx2; i++){ // Loop until you reach the other parenthesis
                if(fact.at(i) == '\'' || fact.at(i) == ','){ // If an invalid char, skip
                    i++;
                } else { // Otherwise, add the val to the tuple
                    t.SetValue(fact.substr(i, i+1));
                }
            }
            database.AddTuple(name, t); // Add the tuple to the right database
        }
         **/
    }
}


Relation Interpreter::EvaluatePredicate(Parameter p) {
    if(p.isConst()){
        //Perform Select 1
    } else {
        // Does the Variable exist in Header?
        //If so, do select type 2
        // Otherwise Project and rename
    }
    return Relation();
}

Relation Interpreter::EvaluateQueries(){
    return Relation();
}

