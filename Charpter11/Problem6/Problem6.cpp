#include "stonewt.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

int main(){
    srand(time(0));
    Stonewt test[6] = {Stonewt(123.32), Stonewt(123.32), Stonewt(333.0)};
    for(int i=3; i<6; i++){
        test[i] = Stonewt(rand());
    }
    Stonewt bench = Stonewt(11, 0.0);
    int count = 0;
    Stonewt maxSt = test[0];
    Stonewt minSt = test[0];
    for(int i=1; i<6; i++){
        maxSt = std::max(maxSt, test[i]);
        minSt = std::min(minSt, test[i]);
        if(test[i] >= bench){
            ++count;
            std::cout << "Heavier than bench: " << test[i] << std::endl;
        } 
    }

    std::cout << "Max: " << maxSt;
    std::cout << "Min: " << minSt;

    return 0;
}