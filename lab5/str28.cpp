#include <iostream>
#include <string>
#include <fstream>
#include "filework.h"
#include <sstream>
void str28() {
    using namespace std;
    std::string line;
    fil(line);
    std::cout << line << std::endl;
    int num = std::stoi(line, 0, 16);
    std::cout << num << std::endl;
    std::ostringstream str;
    str << std::oct << num;
    line = str.str();
    std::cout << line << std::endl;
}