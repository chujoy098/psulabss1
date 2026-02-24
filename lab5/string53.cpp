
#include <iostream>
#include <string>
#include <fstream>
void s53() {
    std::cout<<"enter filename: ";
    std::string filename;
    std::cin>>filename;
    std::ifstream input("");
    if (!input.is_open()) {
        std::cout<<"Error opening file"<<std::endl;
        return;
    }
    char ch;
    int counter = 0;
    while (input.get(ch)) {
        if(std::ispunct(ch)) {
            counter++;
        }
    }
    std::cout<<counter<<"\n";
    input.close();
}