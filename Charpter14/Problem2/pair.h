#ifndef PAIR_H_
#define PAIR_H_
#include <valarray>


typedef std::valarray<int> ArrayInt;

template <class T, class U>
class Pair{
    private:
        T a;
        U b;
    public:
        Pair() { }
        Pair(const T & t, const U & u):a(t), b(u){ }
        virtual ~Pair() { }
        T & first();
        U & second();
        T first() const;
        U second() const;
};

template<class T, class U>
T & Pair<T, U>::first(){
    return a;
}

template<class T, class U>
U & Pair<T, U>::second(){
    return b;
}

template<class T, class U>
T Pair<T, U>::first() const {
    return a;
}

template<class T, class U>
U Pair<T, U>::second() const {
    return b;
}


#endif