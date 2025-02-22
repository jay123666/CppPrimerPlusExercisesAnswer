#include <iostream>

int main() {
    for (int i=0;i<=10;i++) {
        std::cout << "Enter your fuel efficiency in liters per 100 kilometers: ";
        double fuel_efficiency;
        std::cin >> fuel_efficiency;
        double miles_per_gallon = (1/fuel_efficiency) * (62.41*3.785);
        std::cout << "Your fuel efficiency is " << miles_per_gallon << " miles per gallon." << std::endl;
    }
    return 0;
}