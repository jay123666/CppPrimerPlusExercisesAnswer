#include <iostream>

int main() {
    std::cout << "Enter the seconds: ";
    long long seconds;
    std::cin >> seconds;
    long days = seconds / 86400;
    long res = seconds % 86400;
    long hours = res / 3600;
    res = res % 3600;
    long minutes = res / 60;
    long sec = res % 60;
    std::cout << "The result is " << days << " days, " << hours << " hours, " << minutes << " minutes, and " << sec << " seconds." << std::endl;
    return 0;
}