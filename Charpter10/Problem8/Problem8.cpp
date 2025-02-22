#include "List.h"
#include <iostream>

template <typename T>
void plus(Item<T> &item){
    item.data += 1;
}

int main(){
    List<int> testlist;
    testlist.add(1);
    testlist.add(2);
    testlist.add(3);
    std::cout << testlist.isEmpty() << std::endl;
    std::cout << testlist.isFull() << std::endl;
    Item<int> item = {1, nullptr};
    testlist.visit(plus<int>);
    return 0;
}
