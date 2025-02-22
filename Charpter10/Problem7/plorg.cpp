#include "plorg.h"
#include <iostream>
#include <cstring>

Plorg::Plorg(const char * fullname, int CI){
    std::strcpy(this->fullname, fullname);
    this->fullname[19] = '\0';
    this->CI = CI;
}

void Plorg::moidfyCI(int CI){
    this->CI = CI;
}

void Plorg::showPlorg() const{
    std::cout << "Fullname: " << fullname << std::endl;
    std::cout << CI << std::endl;
}