#include "Person.h"
#include <cstring>
#include <iostream>

Person::Person(const std::string & ln, const char * fn){
    this->lname = ln;
    std::strcpy(this->fname, fn);
}

void Person::Show() const{
    std::cout << this->fname << " " << this->lname << std::endl; 
}

void Person::FormalShow() const{
    std::cout << this->lname << ", " << this->fname << std::endl;
}