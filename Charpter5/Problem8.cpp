#include <iostream>
#include <cstring>

int main() {
    std::cout << "Enter words (to stop, type the word done): " << std::endl;
    int bufferSize = 100;
    char buffer[bufferSize];
    int wordCount = 0;
    while (std::cin >> buffer) {
        if (std::strcmp(buffer, "done")==0)
            break;
        ++wordCount;
    }
    std::cout << "You entered a total of " << wordCount << " of words." << std::endl;
}