#include <algorithm>
#include <fstream>
#include <set>
#include <string>

std::set<std::string> mergeSet(const std::set<std::string> & s1, const std::set<std::string> & s2);

int main(){
    std::set<std::string> matFrd, patFrd;
    std::ifstream fcin1("mat.dat"), fcin2("pat.dat");
    std::string frd;
    while(getline(fcin1, frd)){
        matFrd.insert(frd);
    }
    while(getline(fcin2, frd)){
        patFrd.insert(frd);
    }

    std::set<std::string> comFrd = mergeSet(matFrd, patFrd);

    std::ofstream fout("matnpat.dat");
    for(std::string name: comFrd){
        fout << name << std::endl;
    }

    return 0;
}

std::set<std::string> mergeSet(const std::set<std::string> & s1, const std::set<std::string> & s2){
    std::set<std::string> res;
    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(res, res.end()));
    return res;
}