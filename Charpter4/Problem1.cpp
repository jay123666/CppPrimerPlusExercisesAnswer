#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <array>


char * getGrade(char grade) {
    char * newGrade = &grade;
    if (grade == 'F' || grade == 'D') {
        return newGrade;
    } else {
        grade++;
        return newGrade;
    }
}


int main() {
    std::cout << "What is your first name? ";
    std::string firstName;
    std::cin >> firstName;
    std::cout << "What is your last name? ";
    std::string lastName;
    std::cin >> lastName;
    std::cout << "What letter grade do you deserve? ";
    char grade;
    std::cin >> grade;
    std::cout << "What is your age? ";
    int age;
    std::cin >> age;
    std::cout << std::endl << "Name: " << lastName << ", " << firstName << std::endl;
    std::cout << "Grade: " << *getGrade(grade) << std::endl;
    std::cout << "Age: " << age << std::endl;
    return 0;
}