#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct patreon{
    std::string name;
    double amount;
};

int main() {
    std::ifstream inFile("Patreons.txt");
    if (!inFile) {
        std::cerr << "Unable to open file Patreons.txt" << std::endl;
        return 1;
    }
    
    std::vector<patreon> greatPatreons;
    std::vector<patreon> normalPatreons;
    std::string line;
    
    // Read the total number of patrons
    if (std::getline(inFile, line)) {
        std::istringstream iss(line);
        int total;
        iss >> total;
    }
    
    // Read each pair of lines (name and amount)
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        std::string name = line;
        if (std::getline(inFile, line)) {
            double amount;
            std::istringstream issAmount(line);
            issAmount >> amount;
    
            if (amount >= 10000) {
                greatPatreons.push_back({name, amount});
            } else {
                normalPatreons.push_back({name, amount});
            }
        }
    }
    std::cout << "Here comes Great Patreons!" << std::endl;
    if (!greatPatreons.empty()) {
        for (patreon p: greatPatreons) {
            std::cout << p.name << ": " << p.amount << std::endl;
        }
    } else {
        std::cout << "none" << std::endl;
    }

    std::cout << "Here comes Patreons!" << std::endl;
    if (!normalPatreons.empty()) {
        for (patreon p: normalPatreons) {
            std::cout << p.name << ": " << p.amount << std::endl;
        }
    } else {
        std::cout << "none" << std::endl;
    }
    return 0;
}