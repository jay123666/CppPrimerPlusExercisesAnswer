#include <iostream>
#include "stonewt.h"

int main(){
    Stonewt incognito = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    incognito.setMode(Stonewt::QUARTZ);
    std::cout << "The celebrity weighted " << incognito;
    wolfe.setMode(Stonewt::QUARTZ);
    std::cout << "The detective weighted " << wolfe;
    taft.setMode(Stonewt::LBS);
    std::cout << "The President weighted " << taft;

    incognito = 276.8;
    taft = 325;
    incognito.setMode(Stonewt::QUARTZ);
    std::cout << "After dinner, the celebrity weighted " << incognito;
    std::cout << "After dinner, the President weighted " << taft;

    std::cout << "Testing plus " << incognito+taft;
    std::cout << "Testing minus " << incognito-taft;
    std::cout << "Testing product " << 2*incognito;


    return 0;
}