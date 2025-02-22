#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
void ShowStr(const string & str);
void GetStrs(ifstream & fin, vector<string> & vs);

class Store{
    private:
        ofstream & fout;
    public:
        Store(ofstream & fout);
        void operator()(const string & str);
};

int main(){
    vector<string> vostr;
    string temp;

    cout << "Enter strings (empty line to quit):\n";
    while(getline(cin, temp) && temp[0]!='\0') vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open()){
        cerr << " Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}

void ShowStr(const string & str){
    cout << str << endl;
}

Store::Store(ofstream & fout):fout(fout){
    if (!fout.is_open()) cout << "Failed to create store object\n";
}

void Store::operator()(const string & str){
    int len = str.length();
    fout.write(reinterpret_cast<const char *>(&len), sizeof(len));
    fout.write(str.data(), len);
}

void GetStrs(ifstream & fin, vector<string> & vs){
    int len; 
    while(fin.read(reinterpret_cast<char *>(&len), sizeof(len))){
        char * ch = new char[len];
        fin.read(ch, len);
        vs.push_back(ch);
        delete [] ch;
    }
}

