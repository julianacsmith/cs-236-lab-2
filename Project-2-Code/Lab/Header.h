//
// Created by Juliana Smith on 10/25/21.
//

#ifndef CS_236_LAB_1_HEADER_H
#define CS_236_LAB_1_HEADER_H
#include <iostream>
#include <vector>
#include <algorithm>

class Header{
private:
    std::vector<std::string> attributes;
public:
    Header(){}
    ~Header(){}
    Header (std::vector<std::string> att){
        attributes = att;
    }
    std::string GetAttribute(int pos){
        return attributes.at(pos);
    }
    std::string GetFirstAttribute(){
        return attributes.at(0);
    }
    void AddAttribute(std::string a){
        attributes.push_back(a);
    }
    int FindAttribute(std::string a){
        for(unsigned int i = 0; i < attributes.size(); i++){
            if(attributes.at(i) == a){
                return i;
            }
        }
        return -1;
    }

    int Size(){
        return attributes.size();
    }

    bool AttributeExists(std::string a){
        if(find(attributes.begin(), attributes.end(), a) != attributes.end()){
            return true;
        }
        return false;
    }

    std::vector<std::string> GetAllAttributes(){
        return attributes;
    }

    void SetAttribute(int pos, std::string a){
        attributes.at(pos) = a;
    }
};
#endif //CS_236_LAB_1_HEADER_H
