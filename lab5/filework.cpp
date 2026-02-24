//
// Created by chujoy on 23.02.2026.
//
#include "filework.h"

void fil(std::string& a) {
    std::cout<<"enter filename: ";
    std::string filename;
    std::cin>>filename;
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cout<<"Error opening file"<<std::endl;
        return;
    }
    getline(input, a);
    input.close();
}
