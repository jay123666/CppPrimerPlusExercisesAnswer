#include <iostream>

void print(char * ch);
void print(char * ch, int n);
static int call_number = 0;

int main() {
    char ch[] = "asdf";
    print(ch);
    print(ch);
    print(ch, 3);
    return 0;
}


void print(char * ch){
    std::cout << ch << std::endl;
    call_number++;
}

void print(char * ch, int n){
    call_number++;
    int time_to_print = (n == 0) ? 0 : call_number;
    for(int i=0; i<time_to_print; i++) {
        std::cout << ch << std::endl;
    }
} 
