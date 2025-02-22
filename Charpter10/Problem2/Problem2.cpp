#include "Person.h"
#include <iostream>

int main() {
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.Show();
    one.FormalShow();
    std::cout << std::endl;
    two.Show();
    two.FormalShow();
    std::cout << std::endl;
    three.Show();
    three.FormalShow();
    std::cout << std::endl;
    return 0;
}