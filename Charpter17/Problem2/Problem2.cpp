#include <iostream>
#include <fstream>
#include <string>

int main(){
    using namespace std;
    cout << "Please enter the filename: ";
    string filename;
    getline(cin, filename);
    ofstream fout(filename+".txt");
    cout << "Please enter the content: ";
    string content;
    while(getline(cin, content) && content!="quit"){
        fout << content << '\n';
    }
    fout.close();
    fout.clear();
    cout << "Done.\n";
    return 0;
}