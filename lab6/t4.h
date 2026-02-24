//
// Created by chujoy on 24.02.2026.
//

#ifndef LAB6_T4_H
#define LAB6_T4_H
#include <iostream>
#include <string>
#include <vector>
struct car {
    int yearmake;
    std::string brand;
    std::string model;
};
void addcar(std::vector<car>& lib);
void viewcar(std::vector<car>& lib);
void seeamount(std::vector<car>& lib);
void searchbyyear(std::vector<car>& lib);
#endif //LAB6_T4_H