#include "workermi.h"
#include <iostream>

Worker::~Worker() { }

void Worker::Get(){
    std::getline(std::cin, fullname);
}

void Worker::Data() const {
    std::cout << "Name: " << fullname << std::endl;
}


void Waiter::Get(){
    std::cout << "Enter panache: ";
    std::cin >> panache;
    while(std::cin.get()!='\n') continue;
}

void Waiter::Data() const {
    std::cout << "Waiter Panache: " << panache << std::endl;
}

void Waiter::Set(){
    std::cout << "Enter name of waiter: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const {
    std::cout << "Category: Waiter.\n";
    Worker::Data();
    Data();
}

void Fucker::Get(){
    std::cout << "Enter fuck lvl: ";
    std::cin >> fuck_lvl;
    while(std::cin.get()!='\n') continue;
}

void Fucker::Data() const {
    std::cout << "Fucker level: " << fuck_lvl << std::endl;
}

void Fucker::Set() {
    std::cout << "Enter name of Fucker: ";
    Worker::Get();
    Get();
}

void Fucker::Show() const {
    std::cout << "Category: Fucker.\n";
    Worker::Data();
    Data();
}

void WaiterFucker::Get(){
    std::cout << "Enter year of exp: ";
    std::cin >> exp;
    while(std::cin.get()!='\n') continue;
    Waiter::Get();
    Fucker::Get();
}

void WaiterFucker::Data() const {
    std::cout << "Year of experiences: " << exp << std::endl;
    Waiter::Data();
    Fucker::Data();
}

void WaiterFucker::Set() {
    std::cout << "Enter name of WaiterFucker: ";
    Worker::Get();
    Get(); 
}

void WaiterFucker::Show() const {
    std::cout << "Category: WaiterFucker.\n";
    Worker::Data();
    Data(); 
}

