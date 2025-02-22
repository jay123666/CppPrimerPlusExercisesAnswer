#include "Account.h"
#include <cstring>
#include <iostream>


Account::Account(std::string name, char * accountNumber, double balance){
    this->name = name;
    std::strcpy(this->accountNumber, accountNumber);
    this->balance = balance;
}

Account::~Account(){
    std::cout << "Bye: " << this->accountNumber << std::endl;
}

void Account::show() const{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Account Number: " << this->accountNumber << std::endl;
    std::cout << "Balance: " << std::to_string(this->balance) << std::endl;
}

void Account::deposit(double amount) {
    this->balance += amount;
}

void Account::withdraw(double amount) {
    if (this->balance < amount) {
        std::cout << "Remaining balance is less than your withdrawing amount" << std::endl;
        return;
    }
    this->balance -= amount;
}
