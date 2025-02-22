#include "cow.h"
#include <iostream>

void copy(Cow c);

int main() {
    Cow c1 = Cow("Guochen", "Golf", 39);
    Cow c2 = c1;
    c1.ShowCow();
    c2.ShowCow();
    copy(c2);
    return 0;
}

void copy(Cow c){
    c.ShowCow();
}