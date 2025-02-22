#include <iostream>


//The order of basecase matters!
template <typename T>
long double sum_value(T value){
    return value;
}

template <typename T, typename... Args>
long double sum_value(T value, Args... args){
    return value+sum_value(args...);
}


int main(){
    std::cout << sum_value(1,2,3,4,5,6,7) << std::endl;
    return 0;
}