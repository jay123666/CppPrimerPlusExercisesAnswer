#include <iostream>
#include <limits>

void inch_to_feet(int inch) {
    const int feet_per_inch = 12;
    int feet = inch / feet_per_inch;
    int remain_inch = inch % feet_per_inch;
    std::cout << "The result is " << feet << " feet and " << remain_inch << " inch." << std::endl; 
}


int main() {
    while (true) {
        std::cout << "Choose your inch: ";
        int inch;
        std::cin >> inch;
        inch_to_feet(inch);
    }
    return 0;
}