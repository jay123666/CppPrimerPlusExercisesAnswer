#include "string2.h"
#include <cstring>
#include <cctype>
#include <cmath>

int String::num_strings = 0;

int String::HowMany(){
    return num_strings;
}

String::String(const char * s){
    len = strlen(s);
    str = new char[len+1];
    strncpy(str, s, 31);
    num_strings++;
}

String::String(){
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st){
    len = st.len;
    str = new char[len+1];
    strcpy(str, st.str);
    num_strings++;
}

String::~String(){  
    delete [] str;
    num_strings--;
}

void String::stringLow(){
    for(int i=0; i<len; i++){
        str[i] = tolower(str[i]);
    }
}

void String::stringUp(){
    for(int i=0; i<len; i++){
        str[i] = toupper(str[i]);
    }
}

int String::has(const char c) const {
    int res=0;
    for(int i=0; i<len; i++){
        if(str[i]==c){
            res++;
        }
    }
    return res;
}

String & String::operator=(const String & st){
    if (this==&st) {
        return *this;
    }
    delete [] str;
    len = st.len;
    str = new char[len+1];
    strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char * ch){
    delete [] str;
    len = strlen(ch);
    str = new char[len+1];
    strcpy(str, ch);
    return *this;
}

char & String::operator[](int i){
    return str[i];
}

const char & String::operator[](int i) const {
    return str[i];
}

bool operator<(const String & st1, const String & st2){
    return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2){
    return (strcmp(st1.str, st2.str) > 0);
}

String operator+(const String & st1, const String & st2){
    int len1 = strlen(st1.str);
    int len2 = strlen(st2.str);
    char * str = new char[len1+len2+1];
    strcpy(str, st1.str);
    strcat(str, st2.str);
    String res(str);
    delete [] str;
    return res;
}

bool operator==(const String & st1, const String & st2){
    return (strcmp(st1.str, st2.str) == 0);
}

std::ostream & operator<<(std::ostream & os, const String & st){
    os << st.str;
    return os;
}

std::istream & operator>>(std::istream & is, String & st){
    char ch[String::CINLIM]; 
    is.get(ch, String::CINLIM);
    if (is){
        st = ch;
    }
    while(is && is.get()!='\n') continue;
    return is;
}


