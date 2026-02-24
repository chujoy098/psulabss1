//
// Created by chujoy on 22.02.2026.
//
#include "array_io.h"
#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <vector>
void arrinput(int n, int m, std::vector<std::vector<int>>& arr)
{
    srand(time(NULL));
    std::cout << "Random or user-defined or from file?\n"
                 "1 - random\n"
                 "2 - user-defined"
                 "3 - from file\n"
                 "enter y/n: ";
    int choice;
    do {
        std::cin >> choice;
    }while (choice != 1 && choice != 2 && choice != 3);
    if (choice == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = rand() % 200;
                std::cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << '\n';
            }
        }
    }
    else {
        if (choice == 2) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    std::cout << "arr[" << i << "][" << j << "] = ";
                    std::cin >> arr[i][j];
                }
            }
        }
        else {
            std::cout << "Enter name of file(must be in same directory): ";
            std::string name;
            std::cin >> name;
            std::ifstream f(name);
            if (!f.is_open()) {
                std::cout << "File not found" << std::endl;
                return;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    f>>arr[i][j];
                }
            }
            f.close();
        }
        }
    }
void arroutput(int n, int m, std::vector<std::vector<int>>& arr)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << '\t';
        }
        std::cout <<'\n';
    }

}