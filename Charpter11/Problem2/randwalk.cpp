#include "vect.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

int main(){
    using namespace std;
    using namespace VECTOR;
    srand(time(0));
    double direction;
    Vector step;
    Vector result=Vector();
    unsigned long steps = 0;
    ofstream outFile("output.txt");

    double target;
    double dstep;
    cout << "Enter target distance: (q to quit): ";
    while(cin >> target){
        cout << "Enter step length: ";
        if (!(cin >> dstep)){
            break;
        }
        outFile << "Target Distance: " << target << ", Step Size: " << dstep << endl;
        cout << steps << ": " << result; 
        while(result.magval() < target){
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            ++steps;
            cout << steps << ": " << result << endl; 
            outFile << steps << ": " << result << endl; 
        }
        cout << "After " << steps << " steps, the subject has the following location:\n";
        cout << result << endl;
        outFile << "After " << steps << " steps, the subject has the following location:\n";
        outFile << result << endl;
        result.polar_mode();
        cout << "or\n" << result << endl;
        cout << "Average outward distance per step = " << result.magval()/steps << endl;
        outFile << "or\n" << result << endl;
        outFile << "Average outward distance per step = " << result.magval()/steps << endl;

        steps = 0;
        result.reset(0, 0, Vector::RECT);
        cout << "Enter target distance: (q to quit): ";
        outFile << endl;
        outFile << endl;
    }

    cout << "Bye.\n";
    outFile << "Bye.\n";
    outFile.close();
    cin.clear();
    while(cin.get()!='\n') continue;

    return 0;
}