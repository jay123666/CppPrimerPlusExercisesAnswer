#include "plorg.h"
#include <iostream>

int main() {
    std::cout << "Enter Name and CI to create Plorg." << std::endl;
    char ch, fullname[20];
    int len = 0;
    while(std::cin.get(ch) && ch!='\n' && len<19){
        fullname[len] = ch; 
        ++len;
    }
    fullname[len] = '\0';
    std::cin >> len;
    Plorg p(fullname, len);
    p.showPlorg();
    p.moidfyCI(12);
    p.showPlorg();
    p.moidfyCI(33);
    p.showPlorg();
    return 0;
}