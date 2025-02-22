#include "stack.h"
#include <iostream>

int main(){
    double sum=0;
    Stack s;
    Item i1 = {"Guochen Wang", 1};
    Item i2 = {"Guochen Wang", 2};
    Item i3 = {"Guochen Wang", 3};
    s.show();
    s.push(i1);
    s.show();
    s.push(i2);
    s.show();
    Item i4 = s.pop(); 
    s.show();

    sum += i4.payment;

    std::cout << sum << std::endl;
    s.push(i3);
    s.show();
    i4 = s.pop(); 
    s.show();

    sum += i4.payment;

    std::cout << sum << std::endl;
    i4 = s.pop(); 
    s.show();

    sum += i4.payment;

    std::cout << sum << std::endl;
    return 0;
}