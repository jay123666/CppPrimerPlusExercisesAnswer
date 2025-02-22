#include "wine.h"
#include <iostream>
#include <cstring>

Wine::Wine():pair(){
    label = new char[1];
    label[0] = '\0';
    year = 0;
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[]):year(y),pair(ArrayInt(yr, y), ArrayInt(bot, y)){
    label = new char[strlen(l) + 1];
    strcpy(label, l);
}

Wine::Wine(const char * l, int y):year(y),pair(ArrayInt(y), ArrayInt(y)){
    label = new char[strlen(l) + 1];
    strcpy(label, l);
}

void Wine::GetBottles(){
    std::cout << "Enter Gully Wash data for " << year << " year(s):\n";
    for(int i=0; i<year; i++){
        std::cout << "Enter year: ";
        std::cin >> pair.first()[i];
        while(std::cin.get()!='\n') continue;
        std::cout << "Enter bottles for that year: ";
        std::cin >> pair.second()[i];
        while(std::cin.get()!='\n') continue;
    }
}

char * Wine::Label() const {
    return label;
}

int Wine::sum() const {
    int sum = 0;
    for(int b: pair.second()){
        sum+=b;
    }
    return sum;
}

void Wine::Show() const {
    std::cout << "Wine: " << Label() << std::endl;
    std::cout << "        Year     Bottles\n";
    for(int i=0; i<year; i++){
        std::cout << "        " << pair.first()[i] << "        " << pair.second()[i] << std::endl;
    }
}
