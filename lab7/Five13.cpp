//
// Created by chujoy on 25.02.2026.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
struct student {
    int score;
    std::string name;
};
void f13() {
    std::cout<<"enter filename: ";
    std::string filename;
    std::cin>>filename;
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cout<<"Error opening file"<<std::endl;
        return;
    }
    std::vector<student> students;
    student temp;
    while ( input >> temp.score >> temp.name ) {
        students.push_back(temp);
    }
    input.close();
    for (int i=0; i<students.size()-1; i++) {
        for (int j=0; j<students.size()-1; j++) {
            if (students[j].score > students[j+1].score) {
                std::swap(students[j], students[j+1]);
            }

        }
    }
    for (int i=0; i<students.size()-1; i++) {
        for (int j=0; j<students.size()-1; j++) {
            if (students[j].score == students[j+1].score) {
                if (students[j].name.at(0) < students[j+1].name.at(0)) {
                    std::swap(students[j], students[j+1]);
                }
            }
        }
    }
    std::ofstream output("five13opt.txt");
    for (int i=0; i<students.size()-1; i++) {
        std::cout << students[i].score << " " << students[i].name << std::endl;
        output << students[i].score << " " << students[i].name << std::endl;
    }
    output.close();
}