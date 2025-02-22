#include <iostream>


struct Pizza {
    std::string company;
    double diameter;
    double weight;
};

void inputPizza(Pizza *ele) {
    std::cout << "Type your company: ";
    std::getline(std::cin, ele->company);
    std::cout << "What size? ";
    std::cin >> ele->diameter;
    std::cout << "How much weight? ";
    std::cin >> ele->weight;
    std::cin.ignore();
    return;
};

void outputPizza(Pizza &ele) {
    std::cout << "Company name: " << ele.company << std::endl;
    std::cout << "Diameter: " << ele.diameter << std::endl;
    std::cout << "Weight: " << ele.weight << std::endl;
    return;
}
int main() {
    Pizza *piz = new Pizza;
    inputPizza(piz);
    outputPizza(*piz);
    return 0;
}