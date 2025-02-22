#include <iostream>
#include <cctype>
#include <string>

const int MAX = 50;
void toUpperString(std::string &str);

int main() {
    std::cout << "Enter a string (q to quit): ";
    while (true){
        std::string str;
        std::getline(std::cin, str);
        if (str == "q") break;    
        toUpperString(str);
        std::cout << str << std::endl;
        std::cout << "Next string (q to quit): ";
    }
    return 0;
}

void toUpperString(std::string &str){
    for(char &c: str) {
        c = std::toupper(c);
    }
}

