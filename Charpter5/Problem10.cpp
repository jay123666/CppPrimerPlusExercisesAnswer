#include <iostream>

int main() {
    std::cout << "Enter number of rows: ";
    int row;
    std::cin >> row;
    for (int i=0; i<row; i++) {
        for (int j=0; j<row; j++) {
            if (row-1-j>i) {
                std::cout << ".";
            } else {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
}