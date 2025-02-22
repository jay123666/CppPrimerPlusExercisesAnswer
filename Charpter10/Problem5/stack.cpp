#include "stack.h"
#include <iostream>


bool Stack::push(Item & item){
    if(top < MAX){
        items[++top] = item;
        return true;
    } else {
        std::cout << "Stack overflow" << std::endl;
        return false;
    }
}

Item Stack::pop(){
    if (top > 0){
        return items[top--];
    } else {
        std::cout << "Stack underflow" << std::endl;
        return Item();
    }
}


Item * Stack::peek(){
    if(!this->isEmpty()){
        Item * item = &items[top]; 
        std::cout << item->fullname << ": " << item->payment << std::endl;
        return item;
    } else {
        std::cout << "Nothing to peek" << std::endl;
        return nullptr;
    }
}

bool Stack::isEmpty(){
    return top == 0;
}

bool Stack::isFull(){
    return top == (MAX-1);
}

void Stack::show() const {
    std::cout << std::endl;
    if(top>0){
        for(int i=top; i>0; i--){
            std::cout << "| " << items[i].fullname << ": " << items[i].payment << " |" << std::endl;
        }
    } else {
        std::cout << "| Null |" << std::endl;
    }
    std::cout << std::endl;
}