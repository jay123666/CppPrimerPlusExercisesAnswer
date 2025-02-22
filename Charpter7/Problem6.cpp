#include <iostream>

int Fill_array(double ar[], int size);
void Show_array(double ar[], int size);
void Reverse_array(double ar[], int size);

int main() {
    int size = 10;
    while (true) {
        double * ar = new double[size];
        int len = Fill_array(ar, size);
        Show_array(ar, len);
        Reverse_array(ar, len);
        Show_array(ar, len);
        delete [] ar;
    }
    return 0;
}

int Fill_array(double ar[], int size) {
    std::cout << "Please enter numbers so as to put into the array with maximum size of " << size << std::endl;
    int i = 0;
    while (i < size && (std::cin >> ar[i])) {
        ++i;
    };
    std::cin.clear();
    while(std::cin.get() != '\n') continue;
    return i;
}

void Show_array(double ar[], int size) {
    for (int i=0; i<size; i++) {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}

void Reverse_array(double ar[], int size) {
    for(int i=0; i < size / 2; i++) {
        std::swap(ar[i], ar[size - i - 1]);
    }    
}