//
// Created by Juliana Smith on 10/25/21.
//

#ifndef CS_236_LAB_1_TUPLE_H
#define CS_236_LAB_1_TUPLE_H
#include <iostream>
#include <vector>
#include <algorithm>
class Tuple{
private:
    std::vector<std::string> values;
public:
    Tuple(){}
    ~Tuple(){}
    std::string GetValue(int n){
        return values.at(n);
    }
    void SetValue(std::string val){
        values.push_back(val);
    }
    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }
    bool ValExists(std::string v){
        if(find(values.begin(), values.end(), v) != values.end()){
            return true;
        }
        return false;
    }
    int FindValPos(std::string s){
        for(unsigned int i = 0; i < values.size(); i++){
            if (values.at(i) == s){
                return i;
            }
        }
        return -1;
    }
    int GetSize(){
        return values.size();
    }
    std::vector<std::string> GetTuple(){
        return values;
    }
};

#endif //CS_236_LAB_1_TUPLE_H
