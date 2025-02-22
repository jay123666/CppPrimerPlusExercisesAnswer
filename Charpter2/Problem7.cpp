#include <iostream>
void cat(int hour, int minute) {
    if (minute >= 60) {
        hour += minute / 60;
        minute = minute % 60;
    }
    if (hour >= 24) {
        hour = hour % 24;
    }
    std::cout << "Time: " << hour << ":" << minute << std::endl;
}
int main() {
    int hour, minute;
    std::cout << "Enter the number of hours: ";
    std::cin >> hour;
    std::cout << "Enter the number of minutes: ";
    std::cin >> minute;
    cat(hour, minute);
    return 1;
}