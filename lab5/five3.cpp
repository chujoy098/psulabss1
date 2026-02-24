#include <iostream>
#include <string>
#include <fstream>
void f3() {
    std::string a;
    std::cout<<"enter filename: ";
    std::string filename;
    std::cin>>filename;
    std::ifstream input(filename);
    std::ofstream op("FN2.txt");
    if (!input.is_open()) {
        std::cout<<"Error opening file"<<std::endl;
        return;
    }
    while (std::getline(input, a)) {
        if (a.empty()) {
            op << "\n";
            continue;
        }
        size_t signPos = std::string::npos;
        for (size_t i = 1; i < a.size(); ++i) {
            if (a[i] == '+' || a[i] == '-') {
                signPos = i;
                break;
            }
        }
        if (signPos == std::string::npos) {
            op << a << "\n";
            continue;
        }

        size_t eqPos = a.find('=', signPos);
        if (eqPos == std::string::npos) {
            op << a << "\n";
            continue;
        }

        // Extract operands and sign
        std::string lefto  = a.substr(0, signPos);
        char sign                = a[signPos];
        std::string righto = a.substr(signPos + 1, eqPos - signPos - 1);

        // Convert operands to integers
        int left  = std::stoi(lefto);
        int right = std::stoi(righto);

        // Calculate result
        int result = (sign == '+') ? (left + right) : (left - right);
        op << a.substr(0, eqPos + 1) << result << "\n";
    }
    input.close();
    op.close();
    }
