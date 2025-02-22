#include "queue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

bool newcustomer(double x);

const int MIN_PER_HR = 60;
using namespace std;

int main(){
    srand(time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);
    Queue line2(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = (MIN_PER_HR * hours);

    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cus = (MIN_PER_HR / perhour);

    Item temp;
    long turnaway = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    int wait_2_time = 0;
    long line_wait = 0;

    for(int cycle=0; cycle<cyclelimit; cycle++){
        if(newcustomer(min_per_cus)){
            if(line.isfull() && line2.isfull()){
                turnaway++;
            } else {
                customers++;
                temp.set(cycle);
                if (line.queuecount() > line2.queuecount()){
                    line2.enqueue(temp);
                } else {
                    line.enqueue(temp);
                }
            }
        }
        if (wait_time <=0 && !line.isempty()){
            served++;
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += (cycle - temp.when());
        }
        if (wait_2_time <=0 && !line2.isempty()){
            served++;
            line2.dequeue(temp);
            wait_2_time = temp.ptime();
            line_wait += (cycle - temp.when());
        }

        if (wait_time > 0) wait_time--;
        if (wait_2_time > 0) wait_2_time--;
        sum_line += line.queuecount();
        sum_line += line2.queuecount();
    }


    if (customers > 0){
        cout << "customers accepted: " << customers << endl;
        cout << " customers served: " << served << endl;
        cout << " turnaways: " << turnaway << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: " << (double) line_wait / served << " minutes\n";
    } else {
        cout << "No customers!\n" << "Done!\n";
    }


    return 0;
}

bool newcustomer(double x){
    return (rand() * x / RAND_MAX < 1);
}
