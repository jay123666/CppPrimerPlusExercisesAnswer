#include <iostream>
#include <fstream>
#include <string>

int main() {
    using namespace std;
    string ifile1 = "input1.txt"; 
    string ifile2 = "input2.txt";
    ifstream fcin1, fcin2;
    try{
        fcin1.exceptions(ios_base::badbit | ios_base::failbit);
        fcin2.exceptions(ios_base::badbit | ios_base::failbit);
        fcin1.open(ifile1);
        fcin2.open(ifile2); 
    } catch (const ios_base::failure & ff){
        cout << "Invalid file: " << ff.what() << endl;
        return 1;
    }
    fcin1.exceptions(ios_base::goodbit);
    fcin2.exceptions(ios_base::goodbit);   

    cout << "Enter the output file: ";
    string ofile;
    getline(cin, ofile);
    ofstream fout(ofile);
    string line1, line2;
    while(fcin1.peek()!=EOF || fcin2.peek()!=EOF){
        if(fcin1.peek()!=EOF && getline(fcin1, line1)){ 
            fout << line1;
            if(fcin2.peek() != EOF){
                fout << " ";
            } else {
                fout << "\n";
            }
        }
        if(fcin2.peek()!=EOF && getline(fcin2, line2)){
            fout << line2 << "\n";
        }
    }
    cout << "Done\n";
    fout.close();
    fout.clear();
    
    return 0;
}