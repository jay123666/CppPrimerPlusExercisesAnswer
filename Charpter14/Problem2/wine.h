#ifndef WINE_H_
#define WINE_H_
#include <valarray>
#include <string>
#include "pair.h"

typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine: private std::string, private PairArray{
    private:
        int year;
    public:
        Wine(const char * l, int y, const int yr[], const int bot[]);
        Wine(const char * l, int y); 
        void GetBottles();
        const std::string & Label() const;
        int sum() const;
        void Show() const;
};
#endif