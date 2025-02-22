#include "mytime3.h"

Time::Time(int h, int m){
    hours = h;
    minutes = m;
}

void Time::AddMin(int m){
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h){
    hours += h;
}

void Time::Reset(int h, int m){
    hours = h;
    minutes = m;
}

Time operator+(const Time & t1, const Time & t2){
    Time result = Time();
    result.AddHr(t1.hours);
    result.AddHr(t2.hours);
    result.AddMin(t1.minutes);
    result.AddMin(t2.minutes);
    return result;
}

Time operator-(const Time & t1, const Time & t2){
    int tot1, tot2;
    tot1 = t1.minutes + t1.hours * 60;
    tot2 = t2.minutes + t2.minutes * 60;
    Time result = Time();
    result.hours = (tot1 - tot2) / 60;
    result.minutes = (tot1 - tot2) % 60;
    return result;
}

Time operator*(double m, const Time & t){
    int tot = t.minutes + t.hours * 60;
    tot *= m;
    return Time(tot/60, tot%60);
}

std::ostream & operator<<(std::ostream & os, const Time & t){
    os << "The time is: " << t.hours << " hours " << t.minutes << " minutes.";
    return os;
}