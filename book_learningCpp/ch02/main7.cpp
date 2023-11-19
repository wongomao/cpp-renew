#include <iostream>
#include <cmath>

double calc_area_circle(double radius)
{
    constexpr double pi { 3.14159 };
    return pi * std::pow(radius, 2);
}

double calc_area_triangle(double base, double height)
{
    return 0.5 * base * height;
}

int main()
{
    double radius{};
    double height{};
    double base{};

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;
    std::cout << "The area of the circle is " << calc_area_circle(radius) << "\n";
    std::cout << "Enter the height of the triangle: ";
    std::cin >> height;
    std::cout << "Enter the base of the triangle: ";
    std::cin >> base;
    std::cout << "The area of the triangle is " << calc_area_triangle(base, height) << "\n";
    return 0;
}