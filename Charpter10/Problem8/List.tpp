#include <iostream>

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0){
}

template <typename T>
List<T>::~List(){
    Item<T> * current = head;
    while(current!=nullptr){
        Item<T> * backup = current->next;
        delete current;
        current = backup;
    }
}


template <typename T>
void List<T>::add(const T &data){
    Item<T> * item = new Item<T>(data, nullptr);
    if (size) {
        if(size == MAX){
            std::cout << "List overflow" << std::endl;
            return;
        }
        tail->next = item;
    } else {
        head = item;
    }
    ++size;
    tail = item;
}

template <typename T>
bool List<T>::isEmpty() const{
    return size == 0;
}

template <typename T>
bool List<T>::isFull() const{
    return size == MAX;
}

template <typename T>
void List<T>::visit(void (*pf)(Item<T> &item)){
    Item<T> * current = head;
    while(current!=nullptr){
        std::cout << "Visiting item with data: " << current->data << std::endl;
        pf(*current);
        current = current->next;
    } 
        
}