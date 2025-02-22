#include <iostream>
double transfer(double lightYears) {
    return 63240 * lightYears;
}


int main() {
    std::cout << "Enter the number of light years: ";
    float lightYears;
    std::cin >> lightYears;
    std::cout << lightYears << " light years = " << transfer(lightYears) << " astronomical units" << std::endl;
    return 0;
}