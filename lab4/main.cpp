#include <iostream>
void m29();
void m59();
void d3();
void d16();
int main() {
    int n;
    do {
        n = 0;
        std::cout << "Enter a task:\n1. Matrix29\n"
                     "2. Matrix59\n"
                     "3. Darray3\n"
                     "4. Darray16\n"
                     "5. Exit\n"
                     "Enter number (1/2/3...) here: ";
        do {
            std::cin >> n;
        }while (n != 1 && n != 2 && n != 3 && n != 4 && n != 5);
        switch (n) {
            case 1:
                m29();
                break;
            case 2:
                m59();
                break;
            case 3:
                d3();
                break;
            case 4:
                d16();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Wrong number!\n";
        }
    }while (n!=5);
    return 0;
    }