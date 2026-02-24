#include <iostream>
#include "main.h"
int main() {
    int n;
    do {
        n = 0;
        std::cout << "Enter a task:\n"
                     "1. string53\n"
                     "2. str16\n"
                     "3. str23\n"
                     "4. str36\n"
                     "5. str28\n"
                     "6. Task 6-1\n"
                     "7. Five3\n"
                     "8. Exit\n"
                     "Enter number (1/2/3...) here: ";
        do {
            std::cin >> n;
        }while (n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6 && n != 7 && n != 8);
        switch (n) {
            case 1:
                s53();
                break;
            case 2:
                str16();
                break;
            case 3:
                str23();
                break;
            case 4:
                str36();
                break;
            case 5:
                str28();
                break;
            case 6:
                t1();
                break;
            case 7:
                f3();
                break;
            case 8:
                return 0;
            default:
                std::cout << "Wrong number!\n";
        }
    }while (n!=8);
    return 0;
}