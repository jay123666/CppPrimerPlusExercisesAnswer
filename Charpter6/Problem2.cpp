#include <iostream>
#include <cctype>

int main() {
    int size = 10;
    double ch, donation[size], sum;
    int count = 0;
    while (count < 10) {
        std::cin >> ch;
        if (std::cin.fail()) {
            std::cin.clear();
            break;
        }
        donation[count] = ch;
        sum += ch; 
        ++count;
    }
    double avg = (sum / count);
    int res = 0;
    for (double don: donation) {
        if (don > avg)
            res += 1;
    }
    std::cout << "The avg of donation is: " << avg << " and there are " << res << " donation that is larger than avg." << std::endl;
    return 0;
}