#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;
const int NUM = 26;
const string filename = "./wordlist.txt";
void readFile(string fname, vector<string> & wordlist);

int main(){
    srand(time(0));
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);
    vector<string> wordlist;
    if(play == 'y') readFile(filename, wordlist);
    
    while(play == 'y'){
        string target = wordlist[rand() % wordlist.size()];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target){
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos){
                cout << "You already guessed that. Try again.\n";
                continue;
            }
            int loc = target.find(letter);
            if(loc == string::npos){
                badchars += letter;
                guesses -= 1;
                cout << "Oh, bad guess!\n";
            } else {
                attempt[loc] = letter;
                loc = target.find(letter, loc+1);
                while(loc != string::npos){
                    attempt[loc] = letter;
                    loc = target.find(letter, loc+1);
                }
                cout << "Good guess!\n";
            } 
            cout << "Your word: " << attempt << endl;
            if(attempt != target){
                if (badchars.length() > 0) cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }
        }
        if(guesses > 0) {
            cout << "That's right!\n";
        } else {
            cout << "Sorry, the word is " << target << ".\n";
        }
        cout << "Would you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }
    return 0;
}

void readFile(string fname, vector<string> & wordlist){
    ifstream fp(fname);
    string word;
    if(fp.is_open()){
        while(fp >> word){
            wordlist.push_back(word);
        }
        fp.close();
    } else {
        cout << "File Error" << endl;
    }
}