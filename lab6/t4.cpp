//
// Created by chujoy on 24.02.2026.
//
#include "t4.h"

#include <bits/shared_ptr_base.h>

void t4() {
    bool you_didnt_add_cars_yet_moron = true;
    int n;
    std::vector<car> library;
    do {
        std::cout << "Welcome to CAR_PROGRAM\n"
        << "What would you like to do?\n"
        << "1. Add car\n"
        << "2. View car\n"
        << "3. see amount of brand of car\n"
        << "4. Search models by year of make\n"
           "5. kill program\n"
        << "Choose: \n"
        << std::endl;
        do {
            std::cin >> n;
        } while (n<1 || n>5);
        switch (n) {
            case 1:
                addcar(library);
                you_didnt_add_cars_yet_moron = false;
                break;
            case 2:
                if (you_didnt_add_cars_yet_moron) {
                    std::cout << "The library is empty. give me a car first.\n";
                    break;
                }
                viewcar(library);
                break;
            case 3:
                if (you_didnt_add_cars_yet_moron) {
                    std::cout << "The library is empty. give me a car first.\n";
                    break;
                }
                seeamount(library);
                break;
            case 4:
                if (you_didnt_add_cars_yet_moron) {
                    std::cout << "The library is empty. give me a car first.\n";
                    break;
                }
                searchbyyear(library);
                break;
            case 5:
                if (you_didnt_add_cars_yet_moron) {
                    std::cout << "You didn't even give me anything... oh well... Fare well!\n";
                }
                break;
        }
    }while (n!=5);
}

void addcar(std::vector<car>& lib) {
    car temp;
    std::cout<< "Enter year of manufacture of car: ";
    std::cin >> temp.yearmake;
    std::cout<< "Enter car manufacturer: ";
    std::cin >> temp.brand;
    std::cout<< "Enter car model: ";
    std::cin >> temp.model;
    lib.push_back(temp);
    std::cout << "Added new car to library!\n";
}
void viewcar(std::vector<car>& lib) {
    std::cout<< "How would you like to find your car?\n"
    <<"1. By model\n"
    <<"2. By manufacturer\n"
    <<"3. By year of manufacture\n"
    <<"Enter number (1/2/3): "
    <<std::endl;
    int choice;
    do {
        std::cin >> choice;
    }while (choice<1 || choice>3);
    std::string sear;
    switch (choice) {
        case 1:
            std::cout << "Ok. Enter model: ";
            std::cin >> sear;
            std::cout << "Found cars:\n"
            << "\tBRAND" << "\tMODEL" << "\tYEAR\n";
            for (int i = 0; i < lib.size(); i++) {
                if (lib[i].model == sear) {
                    std::cout << "\t" << lib[i].brand << "\t" << lib[i].model << "\t" << lib[i].yearmake << std::endl;
                }
            }
            break;
        case 2:
            std::cout << "Ok. Enter manufacturer: ";
            std::cin >> sear;
            std::cout << "Found cars:\n"
            << "\tBRAND" << "\tMODEL" << "\tYEAR\n";
            for (int i = 0; i < lib.size(); i++) {
                if (lib[i].brand == sear) {
                    std::cout << "\t" << lib[i].brand << "\t" << lib[i].model << "\t" << lib[i].yearmake << std::endl;
                }
            }
            break;
        case 3:
            std::cout << "Ok. Enter year: ";
            std::cin >> choice;
            std::cout << "Found cars:\n"
            << "\tBRAND" << "\tMODEL" << "\tYEAR\n";
            for (int i = 0; i < lib.size(); i++) {
                if (lib[i].yearmake == choice) {
                    std::cout << "\t" << lib[i].brand << "\t" << lib[i].model << "\t" << lib[i].yearmake << std::endl;
                }
            }
            break;
    }
}
void seeamount(std::vector<car>& lib) {
    std::cout << "Ok. Enter manufacturer: ";
    std::string sear;
    std::cin >> sear;
    std::cout << "Found cars: ";
    int counter = 0;
    for (int i = 0; i < lib.size(); i++) {
        if (lib[i].brand == sear) {
            counter++;
        }
    }
    std::cout << counter << std::endl;
}
void searchbyyear(std::vector<car>& lib) {
    std::cout << "Ok. Enter first year: ";
    int year1;
    std::cin >> year1;
    std::cout << "Enter last year: ";
    int year2;
    std::cin >> year2;
    if (year2 < year1) {
        std::swap(year1, year2);
    }
    std::cout << "Found cars:\n"
    << "\tBRAND" << "\tMODEL" << "\tYEAR\n";
    for (int i = 0; i < lib.size(); i++) {
        if (lib[i].yearmake >= year1 && lib[i].yearmake <= year2) {
            std::cout << "\t" << lib[i].brand << "\t" << lib[i].model << "\t" << lib[i].yearmake << std::endl;
        }
    }
}