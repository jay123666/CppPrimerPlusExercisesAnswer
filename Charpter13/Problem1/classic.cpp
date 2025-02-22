#include "classic.h"
#include <cstring>
#include <iostream>

Cd::Cd(const char * s1, const char * s2, int n, double x){
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(){
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd(){ }

void Cd::Report() const {
    std::cout << "Performers: " << performers << std::endl;
    std::cout << "Label: " << label << std::endl;
    std::cout << "selections: " << selections << std::endl;
    std::cout << "playtime: " << playtime << std::endl;
}

Classic::Classic(const char * s1, const char * s2, const char * s3, int n, double x):Cd(s1, s2, n, x){
    strcpy(musics, s3);
}

Classic::Classic() { }

Classic::~Classic() { }

void Classic::Report() const {
    Cd::Report();
    std::cout << "music: " << musics << std::endl;
}