#include <iostream>
#include <array>

int main() {
    std::array<long double, 16> factorials;
    factorials[1] = factorials[0] = 1;
    for (int i=2; i<16; i++) {
        factorials[i] = i*factorials[i-1];
    } 
    for (int i=0; i<16; i++) {
        std::cout << i << "!=" << factorials[i] << std::endl;
    }

}