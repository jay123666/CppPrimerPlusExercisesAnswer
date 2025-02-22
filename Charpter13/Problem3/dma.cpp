#include "dma.h"
#include <cstring>
#include <iostream>


baseDMA::baseDMA(const char * l, int r):DMA(){
    label = new char[strlen(l)+1];
    strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs):DMA(rs){
    label = new char[strlen(rs.label)+1];
    strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA(){
    delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs){
    if(this==&rs) return *this;

    delete [] label;
    label = new char[strlen(rs.label)+1];
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

void baseDMA::view() const {
    std::cout << "Label: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

lacksDMA::lacksDMA(const char * c):DMA(){
    strncpy(color, c, COL_LEN-1);
    color[COL_LEN-1] = '\0';
}

void lacksDMA::view() const {
    std::cout << "Color: " << color << std::endl;
}

hasDMA::hasDMA(const char * s):DMA(){
    style = new char[strlen(s)+1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & rs):DMA(rs){
    style = new char[strlen(rs.style)+1];
    strcpy(style, rs.style);
}

hasDMA::~hasDMA(){
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & rs){
    if(this==&rs) return *this;

    DMA::operator=(rs);
    delete [] style;
    style = new char[strlen(rs.style)+1];
    strcpy(style, rs.style);
    return *this;
}

void hasDMA::view() const {
    std::cout << "Style: " << style << std::endl;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & rs){
    os << (const DMA &) rs;
    os << "Style: " << rs.style << std::endl;
    return os;
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & rs){
    os << (const DMA &) rs;
    os << "Color: " << rs.color << std::endl;
    return os;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs){
    os << (const DMA &) rs;
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}
