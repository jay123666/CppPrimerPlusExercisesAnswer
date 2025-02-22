#include <iostream>
#include "sales.h"

void SALES::setSales(Sales & s, const double ar[], int n){
    double sum=0;
    double max=ar[0], min=ar[0];
    int actual = (4<n) ? 4 : n;
    for (int i=0; i<actual; i++){
        s.sales[i] = ar[i];
        sum += ar[i];
        max = (max>ar[i]) ? max : ar[i];
        min = (min<ar[i]) ? min : ar[i];
    }
    s.average = sum / actual;
    s.max = max;
    s.min = min;
}

void SALES::setSales(Sales & s){
    double sale;
    int n=1;
    std::cout << "Enter sales please: " << std::endl;
    std::cin >> sale;
    while(std::cin.get()!='\n') continue;
    s.sales[n] = sale;
    double sum = sale, max = sale, min = sale;

    while(n<4) {
        std::cout << "Enter sales please: " << std::endl;
        std::cin >> sale;
        while(std::cin.get()!='\n') continue;
        s.sales[n] = sale;
        sum += sale;
        max = (max>sale) ? max : sale;
        min = (min<sale) ? min : sale;

        ++n;
    }
    s.average = sum / 4;
    s.max = max;
    s.min = min;
}

void SALES::showSales(const Sales & s){
    for (const double & sale: s.sales) {
        std::cout << "Sales list: " << sale << std::endl;
    }
    std::cout << "Average is: " << s.average << std::endl;
    std::cout << "Max is: " << s.max << std::endl;
    std::cout << "Min is: " << s.min << std::endl;
}