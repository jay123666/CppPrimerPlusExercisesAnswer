#include "golf.h"
#include <iostream>

int main(){
    Golf g1 = {"Guochen Wang", 18};
    g1.showgolf();
    g1 = g1.setgolf();
    g1.sethandicap(4);
    g1.showgolf();
    return 0;
}