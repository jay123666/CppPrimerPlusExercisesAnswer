#include <iostream>
#include <fstream>
#include <string>

int main(){
    using namespace std;
    cout << "Enter the source file: ";
    string sFile;
    getline(cin, sFile);

    ifstream fcin;
    try{
        fcin.exceptions(ios_base::failbit | ios_base::badbit);
        fcin.open(sFile+".txt");
    } catch(const ios_base::failure & ff){
        cout << "Invalid file " << sFile << endl;
        cout << ff.what() << endl;
        return 1;
    }

    cout << "Enter the output file: ";
    string oFile;
    getline(cin, oFile);
    ofstream fout(oFile+".txt");

    string line;
    fcin.exceptions(ios_base::goodbit);
    while(getline(fcin, line)){
        fout << line << endl;
    }
    fcin.close();
    fout.close();
    cout << "Done\n";

    return 0;
}