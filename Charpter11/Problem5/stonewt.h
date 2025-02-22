#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt{
    public:
        enum Mode {QUARTZ, LBS, FLBS};
    private:
        enum {Lbs_per_stn = 14};
        int stone;
        double pds_left;
        double pounds;
        Mode mode;
    public:
        Stonewt(double lbs, Mode mode=LBS);
        Stonewt(int stn, double lbs, Mode mode=QUARTZ);
        Stonewt();
        ~Stonewt();
        void setMode(Mode mode);

        Stonewt operator+(const Stonewt & st);
        Stonewt operator-(const Stonewt & st);
        Stonewt operator*(const double n);

        friend Stonewt operator*(const double n, Stonewt & st);
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & st);
};

#endif