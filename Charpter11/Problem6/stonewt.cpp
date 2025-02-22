#include <iostream>
#include "stonewt.h"

Stonewt::Stonewt(double lbs, Mode md){
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode = md;
}

Stonewt::Stonewt(int stn, double lbs, Mode md){
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    mode = md;
}

Stonewt::Stonewt(){
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt(){

}

void Stonewt::setMode(Mode md){
    mode = md;
}

Stonewt Stonewt::operator+(const Stonewt & st){
    double tot_lbs = pounds + st.pounds;
    return Stonewt(tot_lbs);
}

Stonewt Stonewt::operator-(const Stonewt & st){
    double tot_lbs = pounds - st.pounds;
    return Stonewt(tot_lbs);
}

Stonewt Stonewt::operator*(const double n){
    double tot_lbs = n*pounds;
    return Stonewt(tot_lbs);
}



Stonewt operator*(const double n, Stonewt & st){
    return st*n;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & st){
    if (st.mode == Stonewt::QUARTZ){
        os << st.stone << " stone, " << st.pds_left << " pounds.\n";
    } else if (st.mode == Stonewt::LBS) {
        os << st.pounds << " pounds.\n";
    } else {
        os << "Invalid mode: " << st.mode;
    }
    return os;
}