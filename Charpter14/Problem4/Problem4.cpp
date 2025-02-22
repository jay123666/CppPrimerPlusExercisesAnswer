#include "person.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int SIZE = 3;
    Person * w_ps[SIZE];
    for(int i=0; i<SIZE; i++){
        std::cout << "Enter your job type: ";
        int type;
        std::cin >> type;
        while(std::cin.get()!='\n') continue;
        switch (type)
        {
        case 1:
            w_ps[i] = new Gunslinger;
            break;
        case 2:
            w_ps[i] = new PokerPlayer;
            break;
        case 3:
            w_ps[i] = new BadDude;
            break;
        }
    }

    std::cout << "Here is staff.\n";
    for(int i=0; i<SIZE; i++){
        w_ps[i]->show();
    }
    for(int i=0; i<SIZE; i++){
        delete w_ps[i];
    }
    return 0;
}