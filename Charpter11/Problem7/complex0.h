#include <iostream>

class complex{
    private:
        double real;
        double img;
    public:
        complex() {real = img = 0.0;}
        complex(double r, double i) {real = r, img = i;}
        void comReset(double r, double i) {real = r, img = i;}

        complex operator+(const complex & com) const {return complex(real+com.real, img+com.img);}
        complex operator-(const complex & com) const {return complex(real-com.real, img-com.img);}
        complex operator*(const complex & com) const {return complex(real*com.real-img*com.img, real*com.img+img*com.real);}
        complex operator~() const {return complex(real, -img);}

        friend complex operator*(const double num, const complex & com) {return complex(num*com.real, num*com.img);}
        friend std::ostream & operator<<(std::ostream & os, const complex & com);
        friend std::istream & operator>>(std::istream & is, complex & com);
};