#include <iostream>
#include <string>

int main() {
    std::cout << "Please enter one of the following choices:" << std::endl;
    std::cout << "c) carnivore p) pianist" << std::endl;
    std::cout << "t) tree g) game" << std::endl;
    std::string str = "A maple is a ";
    char ch = std::cin.get();
    while (ch != 'c' && ch != 'p' && ch != 't' && ch != 'g') {
        std::cout << "Please enter a c, p, t, or g: ";
        std::cin >> ch;
    }
    switch (ch) {
        case 'c': {
            str += "carnivore";
            break;
        }
        case 'p': {
            str += "pianist";
            break;
        }
        case 't': {
            str += "tree";
            break;
        }
        case 'g': {
            str += "game";
            break;
        }
    }
    std::cout << str << std::endl;
    return 0;
}