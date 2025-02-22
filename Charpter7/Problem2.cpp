#include <iostream>
#include <vector>
#include <cmath>

const int maxLen = 10;

void getScore(std::vector<int> &golfs);
int setScore(std::vector<int> &golfs);
void calScore(std::vector<int> &golfs, int count);

int main() {
    std::cout << "Please enter your golf score, you can enter at most 10 results.";
    std::vector<int> golfs;
    int count;
    while (true) {
        golfs.clear();
        count = setScore(golfs);
        getScore(golfs);
        calScore(golfs, count);
    }
    return 0;
}

int setScore(std::vector<int> &golfs){
    int count = 0;
    int golf;
    while (count < 10) {
        std::cin >> golf;
        if (std::cin.fail()){
            std::cin.clear();
            while(std::cin.get() != '\n') continue; //pop up rest of invalid input.
            break;
        }
        golfs.push_back(golf);
        ++count;
    }
    return count;
}

void calScore(std::vector<int> &golfs, int count){
    if (count == 0) {
        std::cout << "The average of your score is: 0" << std::endl;
        return;
    }
    int sum = 0;
    for (int golf: golfs) {
        sum += golf;
    }
    double res = sum / count;
    std::cout << "The average of your score is: " << res << std::endl;
}

void getScore(std::vector<int> &golfs){
    std::cout << "Your list of score is:";
    for (int golf: golfs) {
        std::cout << " " << golf;
    }
    std::cout << std::endl;
}