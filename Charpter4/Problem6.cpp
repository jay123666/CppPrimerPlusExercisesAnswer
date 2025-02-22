#include <iostream>
#include <istream>

struct CandyBar {
    std::string brand;
    double weight;
    int calories;
};

void inputCandy(CandyBar *ele) {
    std::cout << "Choose your brand: ";
    std::getline(std::cin, ele->brand);
    std::cout << "How much weight? ";
    std::cin >> ele->weight;
    std::cout << "How much calories? ";
    std::cin >> ele->calories;
    std::cin.ignore();
    return;
};

void outputCandy(CandyBar &ele) {
    std::cout << "Brand: " << ele.brand << std::endl;
    std::cout << "Weight: " << ele.weight << std::endl;
    std::cout << "Calories: " << ele.calories << std::endl;
    return;
}


int main() {
    int size = 3;
    //CandyBar * candy = new CandyBar[size];
    CandyBar candy[size];
    for (int i = 0; i < size; i++) {
        inputCandy(candy+i); // pass pointer
        outputCandy(*(candy+i)); //pass referrence
    }
    //delete [] candy;
    return 0;
}