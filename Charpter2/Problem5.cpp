#include <iostream>

float temperature(float celcius) {
    return 1.8 * celcius + 32;
}


int main() {
    std::cout << "Please enter a Celsius value: ";
    float celcius;
    std::cin >> celcius;
    std::cout << celcius << " degrees Celsius is equal to " << temperature(celcius) << " degrees farhenheit" << std::endl;
    return 0;
}