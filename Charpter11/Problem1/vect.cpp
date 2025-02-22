#include <cmath>
#include <iostream>
#include "vect.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
    const double Rad_to_deg = 45.0 / atan(1.0);
    Vector::Vector(){
        x = y = ang = mag = 0.0;
        mode = RECT;
    }
    
    Vector::Vector(double n1, double n2, Mode form){
        mode = form;
        if(mode == RECT){
            x = n1;
            y = n2;
            this->set_ang();
            this->set_mag();
        } else if(mode == POL){
            mag = n1;
            ang = n2 / Rad_to_deg;
            this->set_x();
            this->set_y();
        }
    }
    
    void Vector::reset(double n1, double n2, Mode form){
        mode = form;
        if (mode == RECT)
        {
            x = n1;
            y = n2;
            this->set_mag();
            this->set_ang();
        } else if(mode == POL){
            mag = n1;
            ang = n2 / Rad_to_deg;
            this->set_x();
            this->set_y();
        }
        else{
            std::cout << "Incorrect 3rd argument to Vectyor() -- ";
            std::cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    
    
    void Vector::set_mag(){
        mag = sqrt(x*x+y*y);
    }
    
    void Vector::set_ang(){
        if (x==0.0 && y==0.0) 
            ang = 0.0;
        else
            ang = atan2(y, x);
    }
    
    void Vector::set_x(){
        x = mag * cos(ang);
    }
    
    void Vector::set_y(){
        y = mag * sin(ang);
    }
    
    Vector::~Vector(){
    
    }
    
    Vector Vector::operator+(const Vector & b) const {
        return Vector(this->x+b.x, this->y+b.y);
    }
    
    Vector Vector::operator-(const Vector & b) const {
        return Vector(this->x-b.x, this->y-b.y);
    }
    
    Vector Vector::operator-() const {
        return Vector(-x, -y);
    }
    
    Vector Vector::operator*(double n) const {
        return Vector(n*x, n*y);
    }
    
    Vector operator*(double n, const Vector & b){
        return b * n;
    }
    
    std::ostream & operator<<(std::ostream & os, const Vector & b){
        if(b.get_mode() == Vector::RECT){
            os << "(x, y) = (" << b.xval() << ", " << b.yval() << ")";
        } else if (b.get_mode() == Vector::POL){
            os << "(m, a) = (" << b.magval() << ", " << b.angval()*Rad_to_deg<< ")";
        } else {
            os << "Object mode is invalid.";
        }
        return os;
    }
}