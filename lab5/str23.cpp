#include <iostream>
#include <string>
#include <fstream>
#include "filework.h"
/*
 * THIS NEEDS TESTING
 */
void str23() {
    std::string line;
    fil(line);
    int gam;
    std::cout << "Enter gamma (127-255): ";
    do {
        std::cin >> gam;
    }while (gam < 127 || gam > 255);
    for (int i = 0; i < line.length(); i++) {
        if (gam<int(line.at(i))) {
            line.at(i) = (int(line.at(i))-gam);
        }
        else {
            line.at(i) = (gam-int(line.at(i)));
        }
    }
    std::cout << line << std::endl;
    for (int i = 0; i < line.length(); i++) { //decoding
        if (int(line.at(i))-gam>0)
            {line.at(i) = (int(line.at(i))-gam);}
        else {
            line.at(i) = 255-(gam-int(line.at(i)));
        }
    }
    std::cout << line << std::endl;
}