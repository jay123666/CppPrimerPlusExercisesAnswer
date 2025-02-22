#include <iostream>
void mice();
void run();

int main() {
    mice();
    mice();
    run();
    run();
    return 0;
}

void mice() {
    std::cout << "Three blind mice" << std::endl;
}

void run() {
    std::cout << "See how they run" << std::endl;
}