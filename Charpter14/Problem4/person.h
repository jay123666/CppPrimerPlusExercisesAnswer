#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <iostream>
using namespace std;

class Card{
    public:
        enum Suit{CLUBS, DIAMONDS, HEARTS, SPADES};
        Card(Suit s=CLUBS, int r=1):suit(s),rank(r){ } 
        friend ostream & operator<<(ostream & os, const Card & c);
        static const char * suitToString(Suit s);   
    private:
        Suit suit;
        int rank;
};

class Person{
    private:
        string firstName;
        string lastName;
    protected:
        void data() const { cout << firstName << " " << lastName << endl; }
    public:
        Person():firstName("Foo"),lastName("Bar") { }
        virtual void show() const{ data(); }
        virtual ~Person() = 0;
};

class Gunslinger: virtual public Person{
    private:
        int scar;
        double reaction;
    protected:
        void data() const;
    public:
        double Draw() const { return reaction; }
        void show() const;
};

class PokerPlayer: virtual public Person{
    public:
        Card Draw() const; 
        void show() const { return Person::show(); }
};

class BadDude: public Gunslinger, public PokerPlayer{
    protected:
        void data() const;
    public:
        double Gdraw() const { return Gunslinger::Draw(); }
        Card Cdraw() const;
        void show() const;
};

#endif