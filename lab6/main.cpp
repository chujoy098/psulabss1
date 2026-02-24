#include <iostream>
#include "main.h"
int main() {
    int n;
    do {
        n = 0;
        std::cout << "Enter a task:\n"
                     "1. ExamTaskC1\n"
                     "2. T1\n"
                     "3. T4\n"
                     "4. Exit\n"
                     "Enter number (1/2/3...) here: ";
        do {
            std::cin >> n;
        }while (n != 1 && n != 2 && n != 3 && n != 4);
        switch (n) {
            case 1:
                ExamTaskC1();
                break;
            case 2:
                t1();
                break;
            case 3:
                t4();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Wrong number!\n";
        }
    }while (n!=8);
    return 0;
}