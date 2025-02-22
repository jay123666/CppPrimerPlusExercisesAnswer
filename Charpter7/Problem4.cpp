#include <iostream>

long double probability(unsigned number, unsigned picks, unsigned specials);

int main() {
    double number, picks, specials;
    std::cout << "Enter the total number of choices on the game card.\n"
                 "The number of picks allowed.\n"
                 "The number of specials: \n";
    while(std::cin >> number >> picks >> specials){
        std::cout << "You have one chance in " << probability(number, picks, specials) << std::endl;
    }
}

long double probability(unsigned number, unsigned picks, unsigned specials){
    long double res = 1.0;
    for(double n=number, p=picks; p>0; n--, p--){
        res *= n / p;
    }
    res *= specials;
    return res;
}