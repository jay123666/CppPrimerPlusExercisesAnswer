#include <iostream>
#include <cstring>

struct stringy {
    char * str;
    int ct;
};

void set(stringy &beany, const char * testing);
void show(const stringy beany, const int n=1);
void show(const char * testing, const int n=1);


int main() {
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    return 0;
}

void set(stringy &beany, const char * testing) {
    beany.ct = std::strlen(testing);
    beany.str = new char[beany.ct+1];
    std::strcpy(beany.str, testing);
}

void show(const stringy beany, const int n){
    for (int i=0; i<n; i++){
        std::cout << beany.str << std::endl;
    }
}

void show(const char * testing, const int n){
    for (int i=0; i<n; i++){
        std::cout << testing << std::endl;
    }
}