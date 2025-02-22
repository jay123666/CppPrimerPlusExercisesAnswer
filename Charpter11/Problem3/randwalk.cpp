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
    unsigned long maxSteps;
    unsigned long minSteps;
    unsigned long sumSteps = 0;
    ofstream outFile("output.txt");

    double target;
    double dstep;
    int experiments;
    cout << "Enter the number of experiments: ";
    while(!(cin >> experiments)) cout << "Re-enter a valid integer." << endl;
    cout << "Enter target distance: (q to quit): ";
    while(!(cin >> target)) cout << "Re-enter a valid integer." << endl;
    cout << "Enter step length: ";
    while(!(cin >> dstep)) cout << "Re-enter a valid integer." << endl;

    for(int i=0; i<experiments; i++){
        outFile << "Target Distance: " << target << ", Step Size: " << dstep << endl;
        while(result.magval() < target){
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            ++steps;
        }

        maxSteps = i > 1 ? max(maxSteps, steps) : steps;
        minSteps = i > 1 ? min(minSteps, steps) : steps;
        sumSteps += steps;

        outFile << "After " << steps << " steps, the subject has the following location:\n";
        outFile << result << endl;
        result.polar_mode();
        outFile << "or\n" << result << endl;
        outFile << "Average outward distance per step = " << result.magval()/steps << endl;

        steps = 0;
        result.reset(0, 0, Vector::RECT);
        outFile << endl;
        outFile << endl;
    }
    outFile << "Max steps it takes are: " << maxSteps << endl;
    outFile << "Min steps it takes are: " << minSteps << endl;
    outFile << "Average steps it takes are: " << sumSteps/experiments << endl;

    cout << "Bye.\n";
    outFile << "Bye.\n";
    outFile.close();
    cin.clear();
    while(cin.get()!='\n') continue;

    return 0;
}