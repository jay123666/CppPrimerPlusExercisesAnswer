#include <iostream>
#include "golf.h"

const int MAX_GOLFER = 5;

int main() {
    golf * golfers = new golf[MAX_GOLFER];
    for (int i=0; i<5; i++){
        if (!setgolf(golfers[i])) break;
        showgolf(golfers[i]);
    }
    delete [] golfers;
    return 0;
}