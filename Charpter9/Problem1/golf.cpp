#include <iostream>
#include <cstring>
#include "golf.h"

extern const int Len;

void setgolf(golf & g, const char * name, int hc){
    std::strncpy(g.fullname, name, Len - 1);
    g.fullname[Len]  = '\0';
    g.handicap = hc;                  
}

void handicap(golf & g, int hc){
    g.handicap = hc;
}

int setgolf(golf & g){
    std::cout << "Please enter the fullname of golfer: ";
    std::cin.getline(g.fullname, Len);
    if (g.fullname[0] == '\0') {
        return 0;
    }
    std::cout << "Please enter the handicap: ";
    int hc;
    std::cin >> hc;
    handicap(g, hc);
    while(std::cin.get() != '\n') continue;
    return 1;
}

void showgolf(const golf & g) {
    std::cout << "Golfer: " << g.fullname << std::endl;
    std::cout << "Handicap: " << g.handicap << std::endl;
}