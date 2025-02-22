#include "golf.h"
#include <iostream>
#include <cstring>
#include <string>

Golf::Golf(const char * name, int hc){
    std::strncpy(this->fullname, name, Golf::Len - 1);
    this->handicap = hc;
    this->fullname[Golf::Len] = '\0';
}

Golf::~Golf(){
    std::cout << "Bye: " << this->fullname << std::endl;
}

Golf Golf::setgolf(){
    std::cout << "Enter your name: ";
    char ch;
    int l = 0;
    while((ch=std::cin.get())!='\n' && l<Golf::Len-1){
        this->fullname[l] = ch;
        ++l;
    }
    this->fullname[l] = '\0';
    std::cout << "Enter your handicap: ";
    int hc;
    std::cin >> hc;
    while(std::cin.get()!='\n') continue;
    return *this;
}

void Golf::sethandicap(int hc){
    this->handicap = hc;
}

void Golf::showgolf() const{
    std::cout << "Name: " << this->fullname << ", Handicap: " << this->handicap << std::endl;
}
