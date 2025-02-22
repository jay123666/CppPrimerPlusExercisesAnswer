#include <iostream>

int main() {
    std::cout << "Enter you income: ";
    double income;
    double tax;
    while (std::cin >> income  && income >= 0) {
        if (income <= 5000) {
            tax = 0;
        } else if (income > 5000 && income <= 15000) {
            tax = (income-5000) * 0.1;
        } else if (income > 15000 && income <= 35000) {
            tax = (income-15000) * 0.15 + 1500;
        } else {
            tax = (income-35000) * 0.2 + 1500 + 3000;
        }
        std::cout << "Your tax is: " << tax << std::endl;
        std::cout << "Enter you income again: ";
    }
    return 0;
}