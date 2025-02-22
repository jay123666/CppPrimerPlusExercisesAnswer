#include <iostream>

double bmi(double weight, double height) {
    const double inch_to_meter = 0.0254;
    const double lbs_to_kg = 0.453592;
    double bmi = weight * lbs_to_kg / (height * inch_to_meter * height * inch_to_meter);
    return bmi;
}


int main() {
    std::cout << "Enter your weight in lbs: ";
    double weight;
    std::cin >> weight;
    std::cout << "Enter your height in feet and inches: ";
    double inches;
    double feet;
    std::cin >> feet >> inches;
    double height = feet * 12 + inches;
    std::cout << "Your height is " << height << " inches." << std::endl;
    double bmi_result = bmi(weight, height);
    std::cout << "Your BMI is " << bmi_result << std::endl;
    return 0;
}