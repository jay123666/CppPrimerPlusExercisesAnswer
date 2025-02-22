#include <iostream>
#include <cstring>

const int MAX_SIZE = 50;
struct CandyBar{
    char brand[MAX_SIZE];
    double weight;
    int calories;
};

void getCandyBar(const CandyBar candy);
void setCandyBar(CandyBar &candy, const char * brand="Millennium Munch", const double weight=2.85, const int calories=350);


int main() {
    while(true) { 
        std::cout << "Enter your candy brand: ";
        char brand[MAX_SIZE];
        int i=0;
        char ch;
        while(i<MAX_SIZE-1 && std::cin.get(ch) && ch!='\n'){
            brand[i++] = ch;
        }
        brand[i] = '\0';
        std::cout << "Enter the weight of candy: ";
        double weight;
        while (true)
        {
            std::cin >> weight;
            if (std::cin.fail()) {
                std::cout << "Retry" << std::endl;
                std::cin.clear();
                while(std::cin.get()!='\n') continue;
            } else {
                break;
            }
        }
        std::cout << "Enter the calories of candy: ";
        int calories;
        std::cin >> calories;
        while(std::cin.get()!='\n') continue;
        CandyBar c;
        setCandyBar(c, brand, weight, calories);
        getCandyBar(c);
    }
    return 0;
}

void setCandyBar(CandyBar &candy, const char * brand, const double weight, const int calories){
    std::strcpy(candy.brand, brand); 
    candy.weight = weight;
    candy.calories = calories;
}

void getCandyBar(const CandyBar candy){
    std::cout << candy.brand << std::endl;
    std::cout << candy.weight << std::endl;
    std::cout << candy.calories << std::endl;
}