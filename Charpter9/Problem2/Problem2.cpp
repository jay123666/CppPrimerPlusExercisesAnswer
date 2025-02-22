#include <iostream>
#include <string>

const int ArSize = 10;

void strcount(const std::string str);

int main() {
    std::string input;

    std::cout << "Enter a line:\n";
    std::getline(std::cin, input);
    while(input!=""){
        strcount(input);
        std::cout << "Enter next line (empty line to quit):\n";
        std::getline(std::cin, input);
    }

    return 0;
}

void strcount(const std::string str){
    static int total = 0;
    int count = 0;

    std::cout << "\"" << str << "\" contains ";
    count = str.length();
    total += count;
    std::cout << count << " characters\n";
    std::cout << total << " characters total\n";
}