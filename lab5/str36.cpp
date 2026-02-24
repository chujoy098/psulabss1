#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include "filework.h"
void str36() {
    std::string line;
    fil(line);
    int counterup = 0;
    int counterdown = 0;
    int counternum = 0;
    int counterspace = 0;
    int counterblank = 0;
    int counterctrl = 0;
    for (int i = 0; i<line.length(); i++) {
        if (ispunct(line.at(i))) {}
        else {
            if (isspace(line.at(i))) {
                counterspace++;
            }
            if (isupper(line.at(i))) {
                counterup++;
            }
            if (islower(line.at(i))) {
                counterdown++;
            }
            if (isdigit(line.at(i))) {
                counternum++;
            }
            if (isblank(line.at(i))) {
                counterblank++;
            }
            if (iscntrl(line.at(i))) {
                counterctrl++;
            }
        }
    }
    std::cout << "upper: " << counterup << std::endl;
    std::cout << "lower: " << counterdown << std::endl;
    std::cout << "digit: " << counternum << std::endl;
    std::cout << "space: " << counterspace << std::endl;
    std::cout << "blank: " << counterblank << std::endl;
    std::cout << "ctrl: " << counterctrl << std::endl;
    std::cout << "total: " << counterup+counterdown+counternum+counterspace+counterblank+counterctrl << std::endl;
}