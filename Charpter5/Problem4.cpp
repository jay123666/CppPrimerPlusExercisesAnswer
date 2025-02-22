#include <iostream>
#include <cmath>

double daphne(int year) {
    return 100 * (1+0.1*year);
}

double cleo(int year) {
    return 100 * std::pow((1+0.05), year);
}


int main() {
    int year = 0;
    while (daphne(year) >= cleo(year)) {
        ++year;
    }
    std::cout << "It takes " << year <<" years for Cleo preceding Daphne." << std::endl;
    std::cout << "The total MV of investment of both is Cleo: " << cleo(year) << " Daphne: " << daphne(year) << std::endl; 
}