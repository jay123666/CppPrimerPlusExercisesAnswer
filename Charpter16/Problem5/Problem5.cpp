#include <iostream>
#include <string>
#include <algorithm>

template <class T>
int reduce(T ar[], int n);

template <class T>
void show(T ar[], int n);

int main(){
    long arr[] = {9, 1, 2, 3, 4, 5, 5, 6, 7, 7};
    std::string str[] = {"asdf", "asdf", "Guochen Wang", "Guo"};
    int n1 = sizeof(arr) / sizeof(arr[2]);
    int n2 = sizeof(str) / sizeof(str[4]);
    int new_end = reduce(arr, n1);
    int new_end2 = reduce(str, n2); 
    show(arr, new_end);
    show(str, new_end2);

    return 0;
}

template <class T>
int reduce(T ar[], int n){
    std::sort(ar, ar+n);
    auto end = std::unique(ar, ar+n);
    return end - ar;
}

template <class T>
void show(T ar[], int n){
    for(int i=0; i<n; i++){
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}