#include <iostream>
#include "Account.h"

int main() {
    char accNumber[11] = "8880000000";
    Account acc = Account("Guochen Wang", accNumber, 0);
    std::cout << "Enter your amount to deposit: ";
    double amount;
    std::cin >> amount;
    while(std::cin.get()!='\n') continue;
    acc.deposit(amount);
    acc.show();
    std::cout << "Enter Your amount to withdraw: ";
    std::cin >> amount;
    while(std::cin.get()!='\n') continue;
    acc.withdraw(amount);
    acc.show();
    return 0;
}