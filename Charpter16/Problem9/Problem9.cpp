#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <ctime>
#include <random>
#include <utility>

using namespace std;

template<typename Func, typename... Args>
void timer(Func func, Args&&... args);

int main(){
    srand(time(0));
    int SIZE = 1000000;
    vector<int> vi0;
    for(int i=0; i<SIZE; i++) vi0.push_back(rand());
    vector<int> vi(vi0);
    list<int> li;
    for(int v: vi0) li.push_back(v);
    cout << "STL sort timer: ";
    timer([](auto begin, auto end){sort(begin, end);}, vi.begin(), vi.end());

    cout << "list sort timer: ";
    timer([&li](){li.sort();});

    li.assign(vi0.begin(), vi0.end());

    clock_t start = clock();
    vi.assign(li.begin(), li.end());
    sort(vi.begin(), vi.end());
    li.assign(vi.begin(), vi.end());
    clock_t end = clock();
    cout << "New method: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s.\n";

    return 0;
}


template<typename Func, typename... Args>
void timer(Func func, Args&&... args){
    clock_t start = clock();
    func(forward<Args>(args)...);
    clock_t end = clock();
    cout << "Elapsed: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s.\n";
}
