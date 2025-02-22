#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::cout << "Type filename: ";
    char filename[50];
    std::cin >> filename;
    std::ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open()) {
        std::cout << "Cannot open file: " << filename << std::endl;
        return 0;
    }
    char ch;
    int cout = 0;
    while (inFile.good()) {
        inFile >> ch;
        ++cout;
    }
    std::cout << "The file has " << cout << " of characters" << std::endl;
    return 0;
}