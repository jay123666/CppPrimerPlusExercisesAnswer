#include <iostream>
#include <cctype>
#include <string>

int main() {
    std::cout << "Enter words (q to quit):" << std::endl;
    int vowel = 0, consonants = 0, others = 0;
    std::string word;
    while(std::cin >> word && word != "q") {
        char firstChar = word[0];
        if(std::isalpha(firstChar)){
            if (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u'){
                ++vowel;
            } else {
                ++consonants;
            }
        } else {
            ++others;
        }
    }
    std::cout << vowel << " words beginning with vowels." << std::endl;
    std::cout << consonants << " words beginning with consonants." << std::endl;
    std::cout << others << " others." << std::endl;
    return 0;
}