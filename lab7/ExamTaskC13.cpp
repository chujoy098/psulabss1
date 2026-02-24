//
// Created by chujoy on 25.02.2026.
//
#include "ExamTaskC13.h"

#include <algorithm>

void ExamTaskC1() {
    std::cout<<"enter filename: ";
    std::string filename;
    std::cin>>filename;
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cout<<"Error opening file"<<std::endl;
        return;
    }
    int id, year, month, exLength;
    std::cout << "Give me a client code: ";
    std::string code;
    std::cin >> code;
    std::cout << "\nSorting client's entries by highest exercise time per month:\n";
    int minExLength = INT_MAX;
    int i = 0;
    std::vector <form> exList;
    form temp;
    while (input >> temp.length >> temp.year >> temp.month >> temp.ID) {
        exList.push_back(temp);
        i++;
    }
    input.close();
    if (exList.empty()) {
        std::cout<<"Are you trolling? This file is empty or glitched out"<<std::endl;
    }
    std::cout << "ExTime\tYear\tMonth\t" << std::endl;
    for (int i=0; i<exList.size()-1; i++) {
        for (int j=0; j<exList.size()-1; j++) {
            if (exList[j].year > exList[j+1].year) {
                std::swap(exList[j], exList[j+1]);
            }
            std::cout << exList[j].length << "\t" << exList[j].year << "\t" << exList[j].month << "\t" ;
        }
    }
    int tempy = exList[0].year;
    int besttime = -1;
    for (int j=0; j<exList.size(); j++) {
        if (tempy > exList[j].year) {
            if (besttime < exList[j].length) {
                besttime = exList[j].length;
            }
        }
        else {
            std::cout << "Highest exercise time for " << tempy <<  " = " << besttime << " in month " << exList[j-1].month << std::endl;
            tempy = exList[j].year;
            besttime = exList[j].length;
        }
    }
}
