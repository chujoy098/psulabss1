#include "task6.h"
void t6() {
    std::mt19937 rando{std::random_device{}()};
    std::cout << "Password generator.\n"
                 "Enter password length: ";
    int length;
    do {
        std::cin >> length;
    }while (length < 1);
    std::cout << "Which difficulty do you prefer?\n"
                 "1. Low (num only)"
                 "2. Medium (num+letters)"
                 "3. High (num+letters+specials)"
                 "Enter here: ";
    int difficulty;
    do {
        std::cin >> difficulty;
    }while (difficulty < 1 || difficulty > 3);
    switch (difficulty) {
        case 1:
            low(length, rando);
            break;
        case 2:
            med(length, rando);
            break;
        case 3:
            high(length, rando);
            break;
        default:
            std::cout << "grievous error\n";
            break;
    }
}
void low(int len, std::mt19937 ran) {
    std::string str;
    for (int i = 0; i < len; i++) {
        char c;
        c = ran()%10;
        str.push_back(c);
    }
    std::cout << "Your password is: " << str << std::endl;
}
void med(int len, std::mt19937 ran) {
    std::string str;
    for (int i = 0; i < len; i++) {
        char c;
        do {
            c = 33+int((ran()%89)); //ascii below 123(122 = z)
        }while ((c<48) || (c < 65 && c > 57) || (c<97 && c>90));
        str.push_back(c);
    }
    std::cout << "Your password is: " << str << std::endl;
}
void high(int len, std::mt19937 ran) {
    std::string str;
    for (int i = 0; i < len; i++) {
        char c;
        c = 33+int((ran()%94)); //ascii below 127(126 is ~)
        str.push_back(c);
    }
    std::cout << "Your password is: " << str << std::endl;
}