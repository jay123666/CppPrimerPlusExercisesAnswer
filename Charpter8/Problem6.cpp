#include <iostream>
#include <cstring>

template <typename T>
T maxn(T * t, const int n);

template <>
char * maxn<char * >(char * ch[], const int n);


int main() {
    int test1[] = {1,2,3,7,5,4};
    double test2[] = {4.4, 3.3, 6.6, 1.0};
    char str1[] = "asdf";
    char str2[] = "fdsa";
    char str3[] = "fe";
    char str4[] = "123";
    char str5[] = "f";
    char * test3[] = {str3, str2, str1, str4, str5};
    std::cout << maxn(test1, 6) << std::endl;
    std::cout << maxn(test2, 4) << std::endl;
    std::cout << maxn(test3, 5) << std::endl;
    return 0;
}

template <typename T>
T maxn(T * t, const int n){
    T res = *t;
    for (int i=0; i<n; i++) res = (res<*(t+i)) ? *(t+i) : res;
    return res; 
}

template <>
char * maxn<char * >(char * ch[], const int n){
    char * res = ch[0];
    for (int i=0; i<n; i++) res = (std::strlen(res)>=std::strlen(ch[i])) ? res : ch[i];
    return res;
}
