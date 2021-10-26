//
// Created by Juliana Smith on 10/25/21.
//

#ifndef CS_236_LAB_1_TUPLE_H
#define CS_236_LAB_1_TUPLE_H
#include <iostream>
#include <vector>
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
    int GetSize(){
        return values.size();
    }
};

#endif //CS_236_LAB_1_TUPLE_H
