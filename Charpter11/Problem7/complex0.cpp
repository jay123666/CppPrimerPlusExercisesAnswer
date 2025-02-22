#include "complex0.h"
#include <iostream>

std::ostream & operator<<(std::ostream & os, const complex & com){
    os << "(" << com.real << ", " << com.img << "i)";
    return os;
}

std::istream & operator>>(std::istream & is, complex & com){
    double real, img;

    std::cout << "real: ";
    if(!(is >> real)) return is;
    std::cout << "imaginary: ";
    is >> img;
    com.comReset(real, img);
    return is;
}