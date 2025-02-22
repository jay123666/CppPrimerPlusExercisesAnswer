#include <iostream>
#include <algorithm>

int reduce(long ar[], int n);

int main(){
    long arr[] = {8, 1, 2, 2, 3, 3, 3, 4, 5, 4, 5, 4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int new_size = reduce(arr, n);
    for(int i=0; i<new_size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

int reduce(long ar[], int n){
    std::sort(ar, ar+n);
    auto end = std::unique(ar, ar+n);
    return end - ar;
}