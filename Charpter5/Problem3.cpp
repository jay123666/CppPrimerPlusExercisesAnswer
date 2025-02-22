#include <iostream>

int main() {
    std::cout << "Enter a number: ";
    double num, sum=0;
    std::cin >> num;
    while (num != 0) {
        sum += num;
        std::cout << "The total number you enter is: " << sum << std::endl;
        std::cin >> num;
    }
}