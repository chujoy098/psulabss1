//
// Created by chujoy on 22.02.2026.
//
#include <iostream>
#include <string>
#include <fstream>
#include "filework.h"
void str16() {
    std::string line;
    fil(line);
    for (int i=0; i<line.length(); i++) {
        if (isspace(line.at(i))) {
            line.at(i) = 35;
        }
        if (i == line.length()-1) {
            line.at(i) = 33;
        }
    }
    std::cout<<line<<std::endl;
}