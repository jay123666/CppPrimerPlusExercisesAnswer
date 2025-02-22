#include <string>

#define NUM_SIZE 10

class Account {
    private:
        std::string name;
        char accountNumber[NUM_SIZE];
        double balance;
    public:
        Account(std::string name, char * accountNumber, double balance=0);
        ~Account();
        void show() const;
        void deposit(double amount);
        void withdraw(double amount);
};
