#include <iostream>

double fahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

double celsiusToFahrenheit(double celsius)
{
    return celsius * 9 / 5 + 32;
}

int main()
{
    double fahrenheit{}, celsius{};

    std::cout << "Enter the temperature in Fahrenheit: ";
    std::cin >> fahrenheit;
    std::cout << "The temperature in Celsius is: " << fahrenheitToCelsius(fahrenheit) << std::endl;

    std::cout << "Enter the temperature in Celsius: ";
    std::cin >> celsius;
    std::cout << "The temperature in Fahrenheit is: " << celsiusToFahrenheit(celsius) << std::endl;

    return 0;
}