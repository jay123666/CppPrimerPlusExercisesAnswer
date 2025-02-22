#include "classic.h"
#include <cstring>
#include <iostream>

Cd::Cd(const char * s1, const char * s2, int n, double x){
    performers = new char[strlen(s1)+1];
    label = new char[strlen(s2)+1];
    strcpy(performers, s1);
    strcpy(label, s2);

    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & cd){
    performers = new char[strlen(cd.performers)+1];
    label = new char[strlen(cd.label)+1];
    strcpy(performers, cd.performers);
    strcpy(label, cd.label);

    selections = cd.selections;
    playtime = cd.playtime;
}

Cd::Cd(){
    performers = new char[1];
    label = new char[1];
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd(){
    delete [] performers;
    delete [] label;
}

Cd & Cd::operator=(const Cd & cd){
    if(this == &cd) return *this;
    delete [] performers;
    delete [] label;

    performers = new char[strlen(cd.performers)+1];
    label = new char[strlen(cd.label)+1];
    strcpy(performers, cd.performers);
    strcpy(label, cd.label);

    selections = cd.selections;
    playtime = cd.playtime;
    return *this;
}

void Cd::Report() const {
    std::cout << "Performers: " << performers << std::endl;
    std::cout << "Label: " << label << std::endl;
    std::cout << "selections: " << selections << std::endl;
    std::cout << "playtime: " << playtime << std::endl;
}

Classic::Classic(const char * s1, const char * s2, const char * s3, int n, double x):Cd(s1, s2, n, x){
    musics = new char[strlen(s3)+1];
    strcpy(musics, s3);
}

Classic::Classic(const Classic & cls):Cd(cls){
    musics = new char[strlen(cls.musics)+1];
    strcpy(musics, cls.musics);
}

Classic::Classic():Cd() {
    musics = new char[1];
    musics[0] = '\0';
}

Classic::~Classic() { 
    delete [] musics;
}

Classic & Classic::operator=(const Classic & cls){
    if (this == &cls) return *this;
    Cd::operator=(cls);
    delete [] musics;

    musics = new char[strlen(cls.musics)+1];
    strcpy(musics, cls.musics);
    return *this;
}

void Classic::Report() const {
    Cd::Report();
    std::cout << "music: " << musics << std::endl;
}