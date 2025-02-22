#include <iostream>

const int Max = 5;

double * fill_array(double * ar, double * end);
void show_array(const double * ar, const double * end);
void revalue(double r, double * ar, double * end);

int main() {
    double * ar = new double[Max];
    double * end;
    while (true) {
        end = fill_array(ar, ar+Max);
        show_array(ar, end);
        std::cout << "Enter revalutaion factor: ";
        double r;
        while (true) {
            std::cin >> r;
            if (std::cin.fail()) {
                std::cout << "Invalid value, re-enter: ";
                std::cin.clear();
                while(std::cin.get()!='\n') continue;
            } else break;
        }
        revalue(r, ar, end);
        show_array(ar, end);
    }
    delete [] ar;
    return 0;
}

double * fill_array(double * ar, double * end){
    double value;
    std::cout << "Please enter your values ";
    while(ar != end && std::cin>>value) {
        *ar = value; 
        ++ar;
    }
    std::cin.clear();
    while(std::cin.get()!='\n') continue;
    return ar;
}

void show_array(const double * ar, const double * end){
    std::cout << "Here are your values: ";
    while (ar != end){
        std::cout << *ar << " ";
        ++ar;
    }
    std::cout << std::endl;
}

void revalue(double r, double * ar, double * end){
    while (ar != end){
        *ar *= r;
        ++ar;
    }
}
