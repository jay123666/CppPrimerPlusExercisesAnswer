#include <iostream>

typedef double (*FuncPtr)(double x, double y);
double calculate(double x, double y, FuncPtr func);
double add(double x, double y);
double subtract(double x, double y);
FuncPtr funcs[2] = {add, subtract};

int main() {
    std::cout << "Enter a pair of numbers: ";
    double a, b;
    while(std::cin >> a >> b){
        for(int i=0; i<2; i++){
            std::cout << "Here is the result of function " << i+1 << " : " << calculate(a, b, funcs[i]) << std::endl;
        }
    }
    return 0;
}

double calculate(double x, double y, FuncPtr func){
    return func(x, y); 
}

double add(double x, double y){
    return x+y;
}

double subtract(double x, double y){
    return x-y;
}