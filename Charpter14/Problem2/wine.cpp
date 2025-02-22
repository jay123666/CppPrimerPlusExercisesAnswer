#include "wine.h"
#include <iostream>
#include <cstring>

Wine::Wine(const char * l, int y, const int yr[], const int bot[]):std::string(l), year(y),PairArray(ArrayInt(yr, y), ArrayInt(bot, y)){
}

Wine::Wine(const char * l, int y):std::string(l), year(y),PairArray(ArrayInt(y), ArrayInt(y)){
}

void Wine::GetBottles(){
    std::cout << "Enter " << (const std::string &) *this << " data for " << year << " year(s):\n";
    for(int i=0; i<year; i++){
        std::cout << "Enter year: ";
        std::cin >> PairArray::first()[i];
        while(std::cin.get()!='\n') continue;
        std::cout << "Enter bottles for that year: ";
        std::cin >> PairArray::second()[i];
        while(std::cin.get()!='\n') continue;

    }
}

const std::string & Wine::Label() const {
    return (const std::string &) *this;
}

int Wine::sum() const {
    int sum = 0;
    for(int b: PairArray::second()){
        sum+=b;
    }
    return sum;
}

void Wine::Show() const {
    std::cout << "Wine: " << Label() << std::endl;
    std::cout << "        Year     Bottles\n";
    for(int i=0; i<year; i++){
        std::cout << "        " << PairArray::first()[i] << "        " << PairArray::second()[i] << std::endl;
    }
}
