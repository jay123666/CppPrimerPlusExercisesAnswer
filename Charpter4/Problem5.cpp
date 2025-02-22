#include <iostream>

struct CandyBar {
    std::string brand;
    double weight;
    int calories;
};


int main() {
    CandyBar snack = {"Mocha Munch", 2.3, 350};
    std::cout << "Brand: " << snack.brand << std::endl;
    std::cout << "Weight: " << snack.weight << std::endl;
    std::cout << "Calories: " << snack.calories << std::endl;
    return 0;
}