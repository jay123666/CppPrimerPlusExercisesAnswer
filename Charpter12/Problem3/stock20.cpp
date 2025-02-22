#include "stock20.h"
#include <iostream>
#include <cstring>

Stock::Stock(const char * ch, long n, double pr){
    int len = strlen(ch);
    str = new char[len + 1];
    strcpy(str, ch);
    shares = n;
    share_val = pr;
    this->set_tot();
}

Stock::Stock(){
    str = new char[1];
    str[0] = '\0';
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const Stock & s){
    int len = strlen(s.str);
    str = new char[len+1];
    strcpy(str, s.str);
    shares = s.shares;
    share_val = s.share_val;
    total_val = s.total_val;
}


Stock::~Stock(){
    delete [] str;
}

void Stock::buy(long num, double price){
    shares += num;
    share_val = price;
    this->set_tot();
}

void Stock::sell(long num, double price){
    if (num>shares){
        std::cout << "Not enough shares to sell.\n";
    }
    shares -= num;
    share_val = price;
    this->set_tot();
}

void Stock::update(double price){
    share_val = price;
    this->set_tot();
}

const Stock & Stock::topval(const Stock & s) const{
    if(s.total_val > this->total_val){
        return s;
    }  else {
        return *this;
    }
}

Stock & Stock::operator=(const Stock & s){
    if(this == &s){
        return *this;
    }
    delete [] str;
    int len = strlen(s.str);
    str = new char[len+1];
    strcpy(str, s.str);
    shares = s.shares;
    share_val = s.share_val;
    total_val = s.total_val;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const Stock & s){
    std::ios_base::fmtflags orig = os.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::streamsize prec = os.precision(3);

    os << "Company: " << *s.str << " Shares: " << s.shares << '\n';
    os << " Share Price: $" << s.share_val;
    os.precision(2);
    os << " Total Worth: $" << s.total_val << '\n';
    os.setf(orig, std::ios_base::floatfield);
    os.precision(prec);

    return os;
}
