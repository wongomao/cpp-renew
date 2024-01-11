#include <iostream>
#include <vector>
#include <algorithm>

struct Employee
{
    std::string name;
    double salary;
};

void showEmployees(const std::vector<Employee>& employees)
{
    for (const auto& employee : employees)
    {
        std::cout << employee.name << ": " << employee.salary << '\n';
    }
    std::cout << "-------------------------" << std::endl;
}

// Regular function for comparing employees by salary
bool compareBySalary(const Employee& a, const Employee& b)
{
    return a.salary < b.salary;
}

// inline function for comparing employees by salary
inline bool compareBySalaryInline(const Employee& a, const Employee& b)
{
    return a.salary < b.salary;
}

// functor (function object) for comparing employees by salary
class Comparator
{
public:
    constexpr bool operator()(const Employee& a, const Employee& b) const
    {
        return a.salary < b.salary;
    }
};


int main()
{
    std::vector<Employee> employees = {
        {"Alice", 50000.0},
        {"Bob", 45000.0},
        {"Charlie", 60000.0},
        {"Denise", 30000.0},
        {"Elaine", 80000.0}
    };

    // Sort employees by salary using a regular function
    std::sort(employees.begin(), employees.end(), compareBySalary);
    showEmployees(employees);

    std::vector<Employee> employees2 = {
        {"Fred", 50000.0},
        {"Garret", 45000.0},
        {"Hannah", 60000.0},
        {"Irene", 30000.0},
        {"Jasmine", 80000.0}
    };
    // sort employees by salary using an inline function
    std::sort(employees2.begin(), employees2.end(), compareBySalaryInline);
    showEmployees(employees2);

    std::vector<Employee> employees3 = {
        {"Kalvin", 50000.0},
        {"Larry", 45000.0},
        {"Madelaine", 60000.0},
        {"Nancy", 30000.0},
        {"Oda", 80000.0}
    };
    // sort employees by salary using a functor
    std::sort(employees3.begin(), employees3.end(), Comparator{});

    std::vector<Employee> employees4 = {
        {"Paige", 50000.0},
        {"Randall", 45000.0},
        {"Sally", 60000.0},
        {"Ted", 30000.0},
        {"Udah", 80000.0}
    };
    // sort employees by salary using a lambda expression
    std::sort(employees4.begin(), employees4.end(), []
    (const Employee& a, const Employee& b)->bool
    {
        return a.salary < b.salary;
    });
    showEmployees(employees4);

    return 0;
}