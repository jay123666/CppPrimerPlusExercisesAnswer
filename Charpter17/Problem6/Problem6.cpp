#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>
#include "emp.h"

enum classkind{Employee, Manager, Fink, Highfink};
const int MAX = 10;
abstr_emp * pc[MAX];

int main(int argc, char * argv[]){
    using namespace std;
    if(argc != 2){
        cerr << "Usage: a.out filename" << endl;
        exit(EXIT_FAILURE);
    }
    const char * filename = argv[1];
    fstream fio(filename, ios_base::in | ios_base::out | ios_base::app);

    string line;
    int i = 0;
    if(fio.is_open()){
        fio.clear();
        fio.seekg(0, ios_base::beg);
        while(getline(fio, line)){
            vector<string> words;
            string word;
            istringstream iss(line);
            while(iss >> word){
                words.push_back(word);
            }
            switch(stoi(words[0])){
                case Employee:{
                    pc[i] = new employee(words[1], words[2], words[3]);
                    break;
                }
                case Manager:{
                    int inCharge = stoi(words[4]);
                    pc[i] = new manager(words[1], words[2], words[3], inCharge);
                    break;
                }
                case Fink:{
                    pc[i] = new fink(words[1], words[2], words[3], words[4]);
                    break;
                }
                case Highfink:{
                    int inCharge = stoi(words[5]);
                    pc[i] = new highfink(words[1], words[2], words[3], words[4], inCharge);
                    break;
                }
            }
            i++;
        }
        for(int j=0; j<i; j++){
            pc[j]->ShowAll();
            cout << endl;
        }
        for(int j=0; j<i; j++){
            delete pc[j];
        }
    } else {
        cout << "Non-existing file, will create new one\n";
    }

    i=0;
    fio.clear();
    fio.seekp(0, ios_base::end);
    
    //move to the EOF in order to append;
    cout << "Choose the employee you want to add\n";
    cout << "e: employee\n";
    cout << "m: manager\n";
    cout << "f: fink\n";
    cout << "h: highfink\n";

    cout << "employee type: (q to quit): ";
    char ch;
    while(cin.get(ch) && ch!='q'){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch(ch)
        {
            case 'e':{
                pc[i] = new employee;
                break;
            }
            case 'm':{
                pc[i] = new manager;
                break;
            }
            case 'f':{
                pc[i] = new fink;
                break;
            }
            case 'h':{
                pc[i] = new highfink;
                break;
            }
        }

        pc[i]->SetAll();
        pc[i]->WriteAll(fio);
        i++;
        cout << "employee type: (q to quit): ";
    }
    fio.close();

    cout << "These are employees you added:\n\n";
    for(int j=0; j<i; j++){
        pc[j]->ShowAll();
        cout << endl;
    }
    for(int j=0; j<i; j++){
        delete pc[j];
    } 
    return 0;
}