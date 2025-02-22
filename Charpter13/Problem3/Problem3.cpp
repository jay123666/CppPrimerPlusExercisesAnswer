#include "dma.h"
#include <iostream>

const int CLIENTS = 4;
using namespace std;

int main(){
    DMA * p_clients[CLIENTS];

    int type;


    for (int i=0; i<CLIENTS; i++){
        cout << "Enter class type: 1 or 2 or 3\n";
        cin >> type;
        cin.ignore();
        if (type==1){
            char label[100];
            int rating;
            cout << "Enter label and rating: \n";
            cin.getline(label, 100);
            cin >> rating;
            cin.ignore();
            p_clients[i] = new baseDMA(label, rating);

        } else if(type==2){
            cout << "Enter your color: \n";
            char color[40];
            cin.getline(color, 40);
            p_clients[i] = new lacksDMA(color);
        } else if(type==3){
            cout << "Enter your style: \n";
            char style[100];
            cin.getline(style, 100);
            p_clients[i] = new hasDMA(style);
       } else break;
    }

    for (int i=0; i<CLIENTS; i++){
        p_clients[i]->view();
    }

    for (int i=0; i<CLIENTS; i++){
        delete p_clients[i];
    }

    cout << "Done.\n";
    return 0;
}