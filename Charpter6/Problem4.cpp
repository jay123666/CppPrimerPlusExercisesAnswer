#include <iostream>

const int strsize = 100;

struct bop {
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

int main() {
    bop bopData[3] = {
        {"Guochen Wang", "App Dev","9900",1},
        {"Silong Hu", "SDE", "MMP", 2},
        {"Ronghui Zhang", "Hipp", "Damn", 0},
    };
    std::cout << "a. display by name    b.display by title" << std::endl;
    std::cout << "c. display by bopname d. display by preference" << std::endl;
    std::cout << "q. quit" << std::endl;
    std::cout << "Enter your choice: ";
    char ch;
    while ((ch=std::cin.get()) != 'q') {
        for (bop b: bopData) {
            switch (ch) {
                case 'a': {
                    std::cout << b.fullname << std::endl;
                    break;
                }
                case 'b': {
                    std::cout << b.title << std::endl;
                    break;
                }
                case 'c': {
                    std::cout << b.bopname << std::endl;
                    break;
                }
                case 'd': {
                    switch (b.preference) {
                        case 0: {
                            std::cout << b.fullname << std::endl;
                            break;
                        }
                        case 1: {
                            std::cout << b.title << std::endl;
                            break;
                        }
                        case 2: {
                            std::cout << b.bopname << std::endl;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        std::cout << "Next choice: ";
        ch = std::cin.get();
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}