#include <iostream>
#include <string>

struct car {
    std::string vendor;
    int manuYear;
};

void carSetter(car &c, int i) {
    std::string make;
    int year;
    std::cout << "Car #" << i+1 << std::endl;
    std::cout << "Please enter the make: ";
    std::cin.ignore();
    char ch;
    while ((ch = std::cin.get()) != '\n') {
        c.vendor += ch;
    }
    std::cout << "Please enter the year made: ";
    std::cin >> c.manuYear;
}

void carGetter(car &c){
    std::cout << c.manuYear << " " << c.vendor << std::endl;
}

int main() {
    std::cout << "How many cars do you with to catalog? ";
    int carNumber;
    std::cin >> carNumber;
    car * carPointer = new car[carNumber];
    for (int i=0; i<carNumber; i++) {
        carSetter(carPointer[i], i);
    }
    std::cout << "Here is your collection." << std::endl;
    for (int i=0; i<carNumber; i++) {
        carGetter(carPointer[i]);
    }
    delete[] carPointer;
}