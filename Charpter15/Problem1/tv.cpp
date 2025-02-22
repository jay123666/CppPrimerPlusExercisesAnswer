#include "tv.h"
#include <iostream>

using namespace std;
bool Tv::volup(){
    if(volumn < MaxVal) {
        ++volumn;
        return true;
    } else return false;
}

bool Tv::voldown(){
    if(volumn > MinVal){
        --volumn;
        return true;
    } else return false;
}

void Tv::chanup(){
    if(channel < maxchannel) {
        ++channel;
    } else {
        channel=1;
    }
}

void Tv::chandown(){
    if(channel > 1){
        --channel;
    } else {
        channel = maxchannel;
    }
}

void Tv::settings() const {
    cout << "TV is " << (state==Off?"Off":"On") << endl;
    if (state == On){
        cout << "Volume setting = " << volumn << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = " << (mode==Antenna?"Antenna":"Cable") << endl;
        cout << "Input = " << (input==TV?"TV":"DVD") << endl;
    }
}

void Tv::set_remote_mode(Remote & r){
    if(ison()){
        r.remoteMode=(r.remoteMode==r.Normal)?r.Interact:r.Normal;
    }
}

void Remote::showRemoteMode() const {
    cout << "Remote mode = " << (remoteMode==Normal?"Normal":"Interact") << endl;
}