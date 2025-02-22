#ifndef STOCK20_H_
#define STOCK20_H_
#include <iostream>

class Stock{
    private:
        char * str;
        int shares;
        double share_val;
        double total_val;
        void set_tot() { total_val = shares * share_val; }
    public:
        Stock();
        Stock(const char * ch, long n=0, double pr=0.0);
        Stock(const Stock & s);
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        const Stock & topval(const Stock & s) const;
        Stock & operator=(const Stock & s);

        friend std::ostream & operator<<(std::ostream & os, const Stock & s);

};


#endif