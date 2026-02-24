#include <iostream>
#include "main.h"
int main() {
    int n;
    do {
        n = 0;
        std::cout << "Enter a task:\n"
                     "1. Sort1\n"
                     "2. ExamTaskC13\n"
                     "3. Five13\n"
                     "4. Exit\n"
                     "Enter number (1/2/3...) here: ";
        do {
            std::cin >> n;
        }while (n != 1 && n != 2 && n != 3 && n != 4);
        switch (n) {
            case 1:
                s1();
                break;
            case 2:
                ExamTaskC13();
                break;
            case 3:
                f13();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Wrong number!\n";
        }
    }while (n!=8);
    return 0;
}