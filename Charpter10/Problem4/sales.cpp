#include "sales.h"
#include <iostream>
#include <algorithm>

using namespace SALES;

Sales::Sales(const double ar[], const int n){
    int num = std::min(QUARTERS, n);
    int i = 0;
    double sum = 0, average, max=ar[0], min=ar[0];
    for(i; i<num; i++){
        this->sales[i] = ar[i];
        sum += ar[i];
        max = std::max(max, ar[i]);
        min = std::min(min, ar[i]);
    }
    average = sum / i;
    for(i; i<QUARTERS; i++){
        this->sales[i] = 0;
    }
    this->average = average;
    this->max = max;
    this->min = min;
}

Sales::~Sales(){
    std::cout << "Bye: " << this->sales << std::endl;
}

Sales Sales::setSales(){
    std::cout << "Please enter four number of sales." << std::endl;
    double sum=0, max, min;
    std::cin >> this->sales[0];
    sum += this->sales[0];
    max = this->sales[0];
    min = this->sales[0];
    int i = 1;
    while(i<QUARTERS){
        std::cin >> this->sales[i];
        sum += this->sales[i];
        max = std::max(this->sales[i], max);
        min = std::min(this->sales[i], min);
        ++i;
    }
    while(std::cin.get()!='\n') continue;
    double average = sum/i;
    this->average = average;
    this->max = max;
    this->min = min;
    return *this;
}

void Sales::showSales() const{
    std::cout << "Sales: ";
    for(int i=0; i<QUARTERS; i++){
        std::cout << this->sales[i] << " ";
    }
    std::cout << std::endl << "Average: " << this->average << std::endl;
    std::cout << "Max: " << this->max << std::endl;
    std::cout << "Min: " << this->min << std::endl;
}