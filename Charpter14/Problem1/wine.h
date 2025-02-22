#ifndef WINE_H_
#define WINE_H_
#include <valarray>
#include "pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine{
    private:
        char * label;
        int year;
        PairArray pair;
    public:
        Wine(); 
        Wine(const char * l, int y, const int yr[], const int bot[]);
        Wine(const char * l, int y); 
        ~Wine(){ delete [] label; }
        void GetBottles();
        char * Label() const;
        int sum() const;
        void Show() const;
};

#endif