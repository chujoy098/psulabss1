//
// Created by chujoy on 14.02.2026.
//

#include "main.h"
#include "iostream"

int main() {
    int n;
    do {
        std::cout << "Lab 3. Enter task.\n"
                     "Tasks:\n"
                     "1. proc13\n"
                     "2. proc27\n"
                     "3. proc43\n"
                     "4. thetri15\n"
                     "5. reccur18\n"
                     "6. Exit\n"
                     "Enter task here (1/2/3...):";
        do {
            std::cin >> n;
        }while (n!=1 && n!=2 && n!= 3 && n!=4 && n!= 5);
        switch (n) {
            case 1:
                p13();
                break;
            case 2:
                p27();
                break;
            case 3:
                p43();
                break;
            case 4:
                t15();
            case 5:
                r18();
                break;
            case 6:
                break;
            default:
                std::cerr << "Invalid number!" << std::endl;

        }
    }while (n!=5);
}
