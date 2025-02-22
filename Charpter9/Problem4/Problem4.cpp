#include <iostream>
#include "sales.h"

int main() {
    SALES::Sales ss[2];
    double s[3] = {234.2, 2, 4};
    setSales(ss[0], s, 3);
    setSales(ss[1]);
    for (SALES::Sales s: ss){
        showSales(s);
    }
    return 0;
}