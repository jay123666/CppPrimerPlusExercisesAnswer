#include <iostream>

int main() {
    std::cout << "Please enter two numbers: " << std::endl;
    int start, end;
    int sum = 0;
    std::cin >> start;
    std::cin >> end;
    for (int i=start; i<=end; i++) {
        sum += i;
    }
    std::cout << "The sum is: " << sum << std::endl;
}