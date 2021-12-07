//
// Created by Juliana Smith on 12/7/21.
//

#ifndef CS_236_LAB_1_GRAPH_H
#define CS_236_LAB_1_GRAPH_H
#include "Rule.h"
#include "Predicate.h"
#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

class Graph {
private:
    map<int, set<int>> ogGraph;
    map<int, set<int>> reverseGraph;
    vector<bool> visited;
public:
    Graph(){}
    void BuildOriginal(vector<Rule> rules){
        /**
         * First get a single rule from the vector
         * (Save it's index in a variable)
         * then look at the body
         * Find the index of each rule within the body
         * add it to a set
         */
        int idx = 0;
        for (Rule r : rules){ // For every rule in rules
            set<int> edges; // Make a set to hold all the connections (edges)
            for(Predicate p : rules.at(0).GetBody()){ // for every predicate in the rule's body
                string name = p.GetName(); // Get the predicate's name. This should be the same as an existing rule
                int foundRule = FindIndex(rules, name); // Finds the index of that rule within the Rules given
                if(foundRule != -1){ // If we find the rule (Which should always happen
                    edges.insert(foundRule); // Insert the index of the rule as a new edge
                }
            }
            map<int, set<int>>::iterator it = ogGraph.begin(); // Necessary iterator
            ogGraph.insert(it, pair<int, set<int>>(idx, edges)); // Insert the current location (idx) and the edges into the ogGraph
            idx++; // Increment idx for the next rule
        }
    }

    int FindIndex(vector<Rule> rules, string name){ // Helper function
        int i = 0;
        for(Rule r : rules){ // For every rule in rules
            if(r.GetHead().GetName() == name){ // See if the current rule's name matches the given name
                return i; // If so, the return the current index
            }
            i++; // Increment for next loop
        }
        return -1; // Rule doesn't exist, therefore return an invalid index
    }

    void BuildReverse(vector<Rule> rules){
        /*
         * Take the current ogGraph and Reverse it
         *
         * For each key in the map,
         * go through the entire set of edges for that index
         * for each edge,
         */
    }

    void DFS(int idx){
        /**
         * Procedure DepthFirstSearch(v: Vertex)
            mark v
            for each vertex w adjacent from v
                if w is not marked
                    DepthFirstSearch(w)
         */
        visited.at(idx) = true; // Mark's current vertex
        int i = 0; // Keeps track of the current index
        for(int edge : ogGraph.at(idx)){ // For every edge
            if(!visited.at(0)){ // As long as we havent visited it
                DFS(edge); // Perform the search on the next edge
            }
            i++; // Increment i accordingly
        }
    }

    void DFSForestPO(Graph g){
        /**
         * forest := empty
         * for each vertex v in G
         *      clear the visit mark for v
         * for each vertex v in G
         *      if v is not marked
         *          tree := DepthFirstSearch(v)
         *          add tree to forest
         */

    }

    void DFSForestSCC(Graph g){

    }
};

#endif //CS_236_LAB_1_GRAPH_H