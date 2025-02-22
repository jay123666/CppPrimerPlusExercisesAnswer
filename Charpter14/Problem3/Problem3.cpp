#include "queuetp.h"
#include "workermi.h"
#include <iostream>

int main() {
    std::cout << "Enter size of Queue: ";
    int qSize;
    std::cin >> qSize;
    while(std::cin.get()!='\n') continue;
    
    QueueTp<Worker> q(qSize);
    Worker * w_ps[5];
    for(int i=0; i<5; i++){
        std::cout << "Enter your job type: ";
        int type;
        std::cin >> type;
        while(std::cin.get()!='\n') continue;
        switch (type)
        {
        case 1:
            w_ps[i] = new Waiter;
            break;
        case 2:
            w_ps[i] = new Fucker;
            break;
        case 3:
            w_ps[i] = new WaiterFucker;
            break;
        }
        w_ps[i]->Set();
        q.inQueue(*w_ps[i]);
    }

    std::cout << "Here is staff.\n";
    while(!q.isempty()){
        Worker * w;
        q.deQueue(w);
        w->Show();
        delete w;
    }
    return 0;
}