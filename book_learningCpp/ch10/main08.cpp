#include <iostream>

// using function overloading
class Calculator
{
    public:
        // overloaded calculate() method
        int calculate(int a, int b)
        {
            return a + b;
        }

        double calculate(double a, double b)
        {
            return a + b;
        }
};

class ScientificCalculator : public Calculator
{
    public:
        // overloaded calculate() method
        int calculate(int a, int b, int c)
        {
            // use the base class method
            return Calculator::calculate(a, b) * c;
        }

        double calculate(double a, double b, double c)
        {
            return Calculator::calculate(a, b) * c;
        }
};

int main()
{
    Calculator basicCalculator;
    ScientificCalculator scientificCalculator;

    int result1 = basicCalculator.calculate(5, 7);
    double result2 = basicCalculator.calculate(3.5, 2.8);
    int result3 = scientificCalculator.calculate(4, 6, 2);
    double result4 = scientificCalculator.calculate(2.5, 3.2, 1.5);

    std::cout << "Basic Calculator Addition result: " << result1 << " and " << result2 << std::endl;
    std::cout << "Scientific Calculator Multiplication result: " << result3 << " and " << result4 << std::endl;
}