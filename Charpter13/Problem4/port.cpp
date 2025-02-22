#include "port.h"
#include <cstring>
#include <iostream>

Port::Port(const char * br, const char * st, int b){
    brand = new char[strlen(br)+1];
    strcpy(brand, br);
    strncpy(style, st, 19);
    style[19] = '\0';
    bottles = b;
}

Port::Port(const Port & p){
    brand = new char[strlen(p.brand)+1];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 19);
    style[19] = '\0';
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p){
    if(this==&p) return *this;

    delete [] brand;
    brand = new char[strlen(p.brand)+1];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 19);
    style[19] = '\0';
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(const int b){
    bottles+=b;
    return *this;
}

Port & Port::operator-=(const int b){
    if(bottles<b) return *this;

    bottles-=b;
    return *this;
}

void Port::Show() const{
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Kind: " << style << std::endl;
    std::cout << "Bottles: " << bottles << std::endl;
}

VintagePort::VintagePort():Port(){
    nickname = new char[1];
    nickname[0] = '\0';
    year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y):Port(br, "Vintage", b){
    nickname = new char[strlen(nn)+1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp):Port(vp){
    nickname = new char[strlen(vp.nickname)+1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp){
    if(this==&vp) return *this;

    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[strlen(vp.nickname)+1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const{
    Port::Show();
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Year: " << year << std::endl;
}

ostream & operator<<(ostream & os, const Port & p){
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

ostream & operator<<(ostream & os, const VintagePort & p){
    os << (const Port &) p;
    os << ", " << p.nickname << ", " << p.year;
    return os;
}
