#include <iostream>
#include <cctype>

int main() {
    std::cout << "Type: " << std::endl;
    char ch;
    while ((ch=std::cin.get())!='@') {
        if (std::isdigit(ch)) {
            continue;
        } else if (std::islower(ch)) {
            ch=std::toupper(ch);
        } else if (std::isupper(ch)) {
            ch=std::tolower(ch);
        }
        std::cout << ch;
    }
    std::cout << std::endl;
    return 0;
}
