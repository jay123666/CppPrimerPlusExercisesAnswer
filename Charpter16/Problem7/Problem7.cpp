#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <random>

using std::vector;


vector<int> lotto(const int balls, const int n);

int main(){
    vector<int> winner;
    winner = lotto(51, 6);
    std::cout << "Winner is: \n";
    for(int v: winner){
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}

vector<int> lotto(const int balls, const int n){
    vector<int> res;
    for(int i=0; i<balls; i++){
        res.push_back(i);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(res.begin(), res.end(), gen);

    res.resize(n);
    return res;
}