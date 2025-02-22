#include <iostream>
#include <string>

using namespace std;
bool isPalindrome(const string & str);

int main(){
    cout << "Enter your word: ";
    string str;
    while(getline(cin, str) && str != "quit"){
        if(isPalindrome(str)){
            cout << str << " is palindrome." << endl;
        } else {
            cout << str << " isn't palindrome." << endl;
        }
        cout << "Enter your word again: ";
    }
    cout << "Bye!" << endl;
    return 0;
}

bool isPalindrome(const string & str){
    auto left = str.begin();
    auto right = str.end() - 1;
    
    while (left < right) {
        if (*left == *right) {
            ++left;
            --right;
        } else {
            return false;
        }
    }
    return true; 
}