#include <iostream>
#include <array>

void printResult(const std::array<double, 3> &run) {
    double sum = 0;
    for (const double ele: run) {
        sum += ele;
    }
    std::cout << "Your avg result is: " << sum / 3.0 << std::endl;
};

void typeResult(std::array<double, 3> &run){
    for (double &ele: run) {
        std::cout << "Type your result ";
        std::cin >> ele;
    }
    return;
};

int main() {
    std::array<double, 3> run;
    typeResult(run);
    printResult(run);
    return 0;
}