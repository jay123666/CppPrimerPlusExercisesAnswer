#include <iostream>
#include <string>

int main() {
    int monthes = 12;
    std::string listMonth[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int * sales = new int[monthes];
    std::cout << "Enter your sales number: " << std::endl;
    for (int i=0; i<12; i++) {
        std::cin >> sales[i];
    }
    int j = 0;
    for (std::string mon: listMonth) {
        std::cout << mon << " has " << sales[j] << " of sales." << std::endl;
        j++;
    }
    delete[] sales;
}