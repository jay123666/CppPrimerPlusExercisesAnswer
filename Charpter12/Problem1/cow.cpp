#include "cow.h"
#include <iostream>
#include <cstring>

int Cow::num = 0;

Cow::Cow(const char * nm, const char * ho, double wt){
    int len = strlen(ho);
    hobby = new char[len+1];
    strcpy(hobby, ho);
    strcpy(name, nm);
    weight = wt; 
    num++;
}

Cow::Cow(const Cow & c){
    int len = strlen(c.hobby);
    hobby = new char[len+1];
    strcpy(hobby, c.hobby);
    strcpy(name, c.name);
    weight = c.weight;
    num++;
}

Cow::~Cow(){
    num--;
    std::cout << "Total cow: " << num;
    std::cout << " To be del: " << this << std::endl;
    delete [] hobby;
}

Cow::Cow(){
    hobby = new char[1];
    hobby[0] = '\0';
    name[0] = '\0';
    weight = 0.0;
    num++;
}

Cow & Cow::operator=(const Cow & c){
    if (this == &c){
        return *this;
    }
    delete [] hobby;
    int len = strlen(c.hobby);
    hobby = new char[len+1];
    strcpy(hobby, c.hobby);
    strcpy(name, c.name);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const{
    std::cout << "Total cow: " << num;
    std::cout << " The cow: " << name << " likes " << hobby << "and weights: " << weight << std::endl;
}