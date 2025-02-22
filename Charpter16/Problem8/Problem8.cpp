#include <iostream>
#include <algorithm>
#include <set>
#include <string>

std::set<std::string> mergeSet(const std::set<std::string> & s1, const std::set<std::string> & s2);

int main(){
    std::set<std::string> matFrd, patFrd;
    std::cout << "Please enter Mat's friend: ";
    std::string frd;
    while(std::cin>>frd && frd != "quit"){
        matFrd.insert(frd);
    }
    while(std::cin.get() != '\n'){
        continue;
    }
    std::cout << "Please enter Pat's friend: ";
    while(std::cin>>frd && frd != "quit"){
        patFrd.insert(frd);
    }
    std::set<std::string> comFrd = mergeSet(matFrd, patFrd);
    std::cout << "Their friends are: \n";
    for(std::string name: comFrd){
        std::cout << name << " ";
    }
    std::cout << std::endl;

    return 0;
}

std::set<std::string> mergeSet(const std::set<std::string> & s1, const std::set<std::string> & s2){
    std::set<std::string> res;
    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(res, res.end()));
    return res;
}