#include <iostream>

double harmonicAvg(double a, double b);

int main() {
    std::cout << "Please enter two numbers: ";
    double a, b;
    std::cin >> a >> b;
    while ((a!=0)&(b!=0)) {
        std::cout << "The harmonic average of these two number is: " << harmonicAvg(a, b) << std::endl;
        std::cin >> a >> b;
    }
    return 0;
}

double harmonicAvg(double a, double b){
    double res = 2.0 * a * b / (a + b);
    return res;
}