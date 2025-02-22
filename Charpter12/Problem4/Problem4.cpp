#include "stack.h"
#include <iostream>
#include <cctype>

int main() {
    Stack st(1);
    std::cout << st << std::endl;
    unsigned long po;
    st.pop(po);
    std::cout << st << std::endl;
    int n=1;
    while(n<9){
        st.push(n);
        n++;
    }
    std::cout << st << std::endl;
    Stack sst = Stack(st);
    std::cout << sst << std::endl;
    sst.pop(po);
    std::cout << sst << std::endl;
    sst = st; 
    std::cout << sst << std::endl;
    return 0;
}