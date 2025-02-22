#include "cpmv.h"
#include <iostream>

using namespace std;

Cpmv::Cpmv(){
    cout << "default constructor called\n";
    p = new Info();
    p->qcode = "";
    p->zcode = "";
}

Cpmv::Cpmv(string q, string z){
    cout << "constructor called with params: " << q << " " << z << endl;
    p = new Info();
    p->qcode = q;
    p->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp){
    cout << "copy constructor called\n";
    p = new Info();
    p->qcode = cp.p->qcode;
    p->zcode = cp.p->zcode;
}

Cpmv::Cpmv(Cpmv && mv){
    cout << "mv constructor called\n";
    p = mv.p;
    mv.p = nullptr;
}

Cpmv::~Cpmv(){
    cout << "delete cpmv: " << this << endl;
    delete p;
}

Cpmv & Cpmv::operator=(const Cpmv & cp){
    cout << "assign constructor called\n";
    if(&cp==this) return *this;

    delete p;
    p = new Info();
    p->qcode = cp.p->qcode;
    p->zcode = cp.p->zcode;
    return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv){
    cout << "mv assign constructor called\n";
    if(&mv==this) return *this;

    delete p;
    p = mv.p;
    mv.p = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const{
    cout << "operator+ called\n";
    Cpmv res = Cpmv(p->qcode+obj.p->qcode, p->zcode+obj.p->zcode);
    return res;
}

Cpmv Cpmv::operator+=(const Cpmv & obj) const{
    return operator+(obj);
}

void Cpmv::Display() const{
    cout << p->qcode << " " << p->zcode << endl;
}
