#include <iostream>

int main() {
    int distance;
    std::cout << "Enter the distance in furlongs: ";
    std::cin >> distance;
    std::cout << "The distance in yards is " << distance * 220 << std::endl;
    return 0;
}