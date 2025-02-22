#include <iostream>
#include <string>

const int Seasons = 4;
const char Snames[Seasons][20] = {"Spring", "Summer", "Fall", "Winter"};

void fill(double * pa);
void show(double * pa);

int main() {
    double expense[Seasons] = {0, 0, 0, 0};
    fill(expense);
    show(expense);
    return 0;
}

void fill(double * pa){
    for (int i=0; i<Seasons; i++) {
        std::cout << "Enter the expense of " << Snames[i] << ": ";
        std::cin >> pa[i];
    }
}

void show(double * pa){
    std::cout << "Expense" << std::endl;
    double total = 0;
    for(int i=0; i<Seasons; i++) {
        std::cout << Snames[i] << ": " << pa[i] << std::endl;
        total += pa[i];
    }
    std::cout << "Total: " << total << std::endl;
}