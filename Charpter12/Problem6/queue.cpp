#include "queue.h"
#include <cstdlib>

Queue::Queue(int qs):qsize(qs){
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue(){
    Node * temp;
    while(front!=nullptr){
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const{
    return items == 0;
}

bool Queue::isfull() const{
    return items == qsize;
}

int Queue::queuecount() const{
    return items;
}

bool Queue::enqueue(const Item & item){
    if (isfull()) return false;

    Node * node = new Node;
    node->item = item;
    node->next = nullptr;
    items++;

    if (front==nullptr){
        front = node;
    } else{
        rear->next = node;
    }
    rear = node;
    return true;
}

bool Queue::dequeue(Item & item){
    if (isempty()) return false;

    item = front->item;
    
    Node * temp = front;
    front = front->next;
    delete temp;
    items--;

    if(items==0) rear = nullptr;
    return true;
}

Customer::Customer():arrive(0), processtime(0){
}

void Customer::set(long when){
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
