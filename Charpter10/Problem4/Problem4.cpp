#include "sales.h"
#include <iostream>

using namespace SALES;

int main(){
    double ar[QUARTERS] = {1,2,3,4};
    Sales s = Sales(ar, 3);
    s.showSales();
    s.setSales();
    s.showSales();
    return 0;
}