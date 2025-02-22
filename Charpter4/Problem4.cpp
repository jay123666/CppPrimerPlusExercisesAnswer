#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your first name: ";
    std::string firstName;
    std::cin >> firstName;
    std::cout << "Enter your last name: ";
    std::string lastName;
    std::cin >> lastName;
    std::cout << "Here is the information in a single string: " << lastName + ", " + firstName << std::endl;
    return 0;
}