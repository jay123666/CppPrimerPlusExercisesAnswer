#include <iostream>

template <typename T>
T max5(T * t);

int main() {
    int test1[] = {1,2,7,4,5};
    double test2[] = {1.2, 2.2, 7.2, 4.2, 5.2};
    std::cout << max5(test1) << std::endl;
    std::cout << max5(test2) << std::endl;
    return 0;
}

template <typename T>
T max5(T * t){
    T res = *t;
    for(int i=0; i<5; i++) res = (res<*(t+i)) ? *(t+i) : res;
    return res;
}