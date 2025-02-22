#include <iostream>
#include <string>
#include <vector>

struct doner{
    std::string name;
    double amount;
};

int main() {
    std::vector<doner> doners;
    doners.push_back({"Guochen Wang", 100.00});
    doners.push_back({"Silong Hu", 1000.00});
    doners.push_back({"Kyle", 10000.00});


    std::vector<doner> grandDoners;
    std::vector<doner> normalDoners;
    for (doner d: doners) {
        if (d.amount >= 100) {
            grandDoners.push_back(d);
        } else {
            normalDoners.push_back(d);
        }
    }
    std::cout << "Here comes grand doners!:" << std::endl;

    if (!grandDoners.empty()) {
        for (doner d: grandDoners) {
            std::cout << d.name << ": " << d.amount << std::endl;
        }
    } else {
        std::cout << "none" << std::endl;
    }

    std::cout << "Here comes patreons!:" << std::endl;

    if (!normalDoners.empty()) {
        for (doner d: normalDoners) {
            std::cout << d.name << ": " << d.amount << std::endl;
        }
    } else {
        std::cout << "none" << std::endl;
    }
    return 0;
}