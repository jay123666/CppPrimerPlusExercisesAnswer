#include <iostream>

int main(){
    char ch;
    int count = 0;
    std::cout << "Type your words: ";
    while(std::cin.get(ch) && ch!='#'){
        count++;
    }
    std::cout << "You have typed " << count << "number of input.\n";
    return 0;
}