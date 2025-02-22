#include <iostream>

template <typename T>
void SumArray(T arr[], int n);

template <typename T>
void SumArray(T * arr[], int n);

struct debts {
    char name[50];
    double amount;
};

int main() {
    int things[6] = {13, 31, 103, 301, 310, 130};
    debts mr_E[3] = {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0},
    };
    double * pd[3];
    for (int i=0; i<3; i++) {
        pd[i] = &mr_E[i].amount;
    }

    SumArray(things, 6);
    SumArray(pd, 3);
    return 0;
}


template <typename T>
void SumArray(T arr[], int n){
    T sum=0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    std::cout << "The sum of T is: " << sum << std::endl;
}

template <typename T>
void SumArray(T * arr[], int n){
    T sum=0;
    for(int i=0; i<n; i++) {
        sum += *arr[i];
    }
    std::cout << "The sum of *T is: " << sum << std::endl;
}