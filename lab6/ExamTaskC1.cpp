#include <climits>
#include <iostream>
#include <string>
#include <fstream>
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

    int minExLength = INT_MAX;
    int bestID = -1, bestYear = -1, bestMonth = -1, bestExLength = -1;
    while (input >> id >> year >> month >> exLength) {
        if (exLength <= minExLength) {
            minExLength = exLength;
            bestID = id;
            bestYear = year;
            bestMonth = month;
            bestExLength = exLength;
        }
    }
    input.close();
    if (bestID == -1) {
        std::cout << "You messed up somehow!"
                     "File is empty or something"
                     " else failed. Try again!" << std::endl;
        return;
    }
    std::cout << "\nLine with minimum Exercise Length: ";
    std::cout << bestID << " " << bestYear << " " << bestMonth << " " << bestExLength << std::endl;
}