#include "stack.h"
#include <algorithm>

Stack::Stack(int n){ 
    pitems = new Item[std::max(n, 10)];
    for(int i=0; i<n; i++){
        pitems[i] = 0;
    }
    size = n;
    top = n-1;
}

Stack::Stack(const Stack & st){
    pitems = new Item[st.size];
    for(int i=0; i<st.size; i++){
        pitems[i] = st.pitems[i];
    }
    size = st.size;
    top = st.top;
}

Stack::~Stack(){
    delete [] pitems;
}

bool Stack::isempty() const {
    return size == 0;
}

bool Stack::isfull() const {
    return size == MAX;
}

bool Stack::push(const Item & item){
    if (isfull()){
        return false;
    }
    pitems[++top] = item;
    size++;
    return true;
}

bool Stack::pop(Item & item){
    if (isempty()){
        return false;
    }
    item = pitems[top--];
    size--;
    return true;
}

Stack & Stack::operator=(const Stack & st){
    if (this==&st) return *this;

    delete [] pitems;
    pitems = new Item[st.size];
    for(int i=0; i<st.size; i++){
        pitems[i] = st.pitems[i];
    }
    size = st.size;
    top = st.top;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const Stack & st){
    os << "Stack addr: " << &st << std::endl;
    for (int i=0; i<st.size; i++){
        os << "| " << st.pitems[i] << " |\n";
    }
    return os;
}