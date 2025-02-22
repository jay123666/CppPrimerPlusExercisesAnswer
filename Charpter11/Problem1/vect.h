#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

namespace VECTOR{
    class Vector{
        public:
            enum Mode{RECT, POL};        
        private:
            double x;
            double y;
            double ang;
            double mag;
            Mode mode;

            void set_ang();
            void set_mag();
            void set_x();
            void set_y();
        public:
            Vector();
            Vector(double n1, double n2, Mode form=RECT);
            ~Vector();
            void reset(double n1, double n2, Mode form=RECT);
            double xval() const {return x;}
            double yval() const {return y;}
            double magval() const {return mag;}
            double angval() const {return ang;}
            Mode get_mode() const {return mode;}
            void polar_mode() {mode = POL;}
            void rect_mode() {mode = RECT;}

            Vector operator+(const Vector & b) const;
            Vector operator-(const Vector & b) const;
            Vector operator-() const;
            Vector operator*(double n) const;

            friend Vector operator*(double n, const Vector & b);
            friend std::ostream & operator<<(std::ostream & os, const Vector & b);
    };
}
#endif