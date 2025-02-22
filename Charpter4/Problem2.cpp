#include <iostream>
#include <string>

int main() {
    std::string name;
    std::string dessert;

    std::cout << "Enter your name:\n";
    std::cin >> name;
    std::cout << "Enter your favorite dessert:\n";
    std::cin >> dessert;
    std::cout << "I have some delicious " << dessert << " for you, " << name << ".\n"; 
    return 0;
}