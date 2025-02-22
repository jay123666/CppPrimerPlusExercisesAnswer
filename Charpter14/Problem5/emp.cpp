#include <string>
#include <iostream>
#include "emp.h"

using namespace std;

abstr_emp::abstr_emp(){ }
abstr_emp::abstr_emp(const string & fn, const string & ln, const string & j):fname(fn), lname(ln), job(j) { }
abstr_emp::~abstr_emp() { }

void abstr_emp::ShowAll() const {
    cout << "Name: " << lname << ", " << fname << endl;
    cout << "Job: " << job << endl;
}

void abstr_emp::SetAll(){
    cout << "Enter first name and last name: ";
    getline(cin, fname);
    getline(cin, lname);
    cout << "Enter the job: ";
    getline(cin, job);
}

ostream & operator<<(ostream & os, const abstr_emp & e){
    os << e.fname << " " << e.lname << " is a(n) " << e.job << endl;
    return os;
}

employee::employee(){ }
employee::employee(const string & fn, const string & ln, const string & j):abstr_emp(fn, ln, j){ }

void employee::ShowAll() const {
    abstr_emp::ShowAll();
}

void employee::SetAll(){
    abstr_emp::SetAll();
}

manager::manager() { }
manager::manager(const string & fn, const string & ln, const string & j, int ico):abstr_emp(fn, ln, j), inchargeof(ico){ }
manager::manager(const abstr_emp & e, int ico):abstr_emp(e), inchargeof(ico){ }
manager::manager(const manager & m):abstr_emp(m), inchargeof(m.inchargeof){ }

void manager::ShowAll() const {
    abstr_emp::ShowAll();
    cout << "In charge of: " << InChargeOf() << endl;
}

void manager::SetAll(){
    abstr_emp::SetAll();
    setInChargeOf();
}

void manager::setInChargeOf(){ 
    cout << "Enter how many employee you're in charge: ";
    cin >> inchargeof;
    while(cin.get()!='\n') continue;
}

fink::fink(){ }
fink::fink(const string & fn, const string & ln, const string & j, const string & rpo):abstr_emp(fn, ln, j), reportsto(rpo){ }
fink::fink(const abstr_emp & e, const string & rpo):abstr_emp(e), reportsto(rpo){ }
fink::fink(const fink & e):abstr_emp(e),reportsto(e.reportsto){ }

void fink::ShowAll() const {
    abstr_emp::ShowAll();
    cout << "This fink reports to: " << ReportsTo() << endl;
}

void fink::SetAll(){
    abstr_emp::SetAll();
    setReportsTo();
}

void fink::setReportsTo(){
    cout << "Enter your manager: ";
    getline(cin, reportsto);
}

highfink::highfink() { }
highfink::highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico):abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo){ }
highfink::highfink(const abstr_emp & e, const string & rpo, int ico):abstr_emp(e), manager(e, ico), fink(e, rpo){ }
highfink::highfink(const manager & m, const string & rpo):abstr_emp(m), fink(m, rpo){ }
highfink::highfink(const fink & f, int ico):abstr_emp(f), manager(f, ico), fink(f){ }
highfink::highfink(const highfink & h):abstr_emp(h), manager(h), fink(h){ }

void highfink::ShowAll() const {
    abstr_emp::ShowAll();
    cout << "In charge of: " << InChargeOf() << endl;
    cout << "This fink reports to: " << ReportsTo() << endl;
}

void highfink::SetAll() {
    abstr_emp::SetAll();
    manager::setInChargeOf();
    fink::setReportsTo();
}
