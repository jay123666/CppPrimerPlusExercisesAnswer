#include <iostream>
#include <numeric>

int main() {
    const int month = 12;
    int (* saleNumbers)[month] = new int[3][month];
    for(int i=0; i<3; i++) {
        for (int j=0; j<12; j++) {
            saleNumbers[i][j] = i+j;
        }
        std::cout << "The sale number of year " << i+1 << " is " << std::accumulate(saleNumbers[i], saleNumbers[i]+month, 0) << std::endl;
    }

    delete[] saleNumbers;

}