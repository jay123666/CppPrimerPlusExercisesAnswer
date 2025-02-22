#include "person.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

const char * Card::suitToString(Suit s){
    switch(s){
        case CLUBS: return "Clubs";
        case DIAMONDS: return "Diamonds";
        case HEARTS: return "Hearts";
        case SPADES: return "Spades";
        default: return "UNKNOW";
    }
}

ostream & operator<<(ostream & os, const Card & c){
    os << "Card suit: " << c.suitToString(c.suit) << endl;
    os << "Card rank: " << c.rank << endl;
    return os;
}

Person::~Person() { }

void Gunslinger::data() const {
    cout << "Scar: " << scar << endl;
    cout << "reaction: " << Draw() << endl;
}

void Gunslinger::show() const {
    Person::data();
    data();
}

Card PokerPlayer::Draw() const {
    srand(time(0));
    int rank = rand() % 13 + 1;
    Card::Suit suit = static_cast<Card::Suit>(rand() % 4);
    this_thread::sleep_for(chrono::seconds(1));
    return Card(suit, rank);
}

Card BadDude::Cdraw() const{
    return PokerPlayer::Draw();
}

void BadDude::data() const {
    Gunslinger::data();
    cout << Cdraw();
}

void BadDude::show() const {
    Person::data();
    data();
}

