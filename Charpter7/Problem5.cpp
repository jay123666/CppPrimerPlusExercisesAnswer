#include <iostream>

long factorial(unsigned number);

int main() {
    std::cout << "Enter a value to calculate its factorial: ";
    unsigned n;
    std::cin >> n;
    while(!std::cin.fail()) {
        std::cout << "The factorial of " << n << " is " << factorial(n) << std::endl;
        std::cin >> n;
    }
    std::cin.clear();
    while(std::cin.get() != '\n') continue;
}

long factorial(unsigned number) {
    if (number == 0){
        return 1;
    }
    return number * factorial(number-1);
}