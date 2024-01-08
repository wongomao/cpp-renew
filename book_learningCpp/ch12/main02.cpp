#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
void SortData(std::vector<T>& data)
{
    std::sort(data.begin(), data.end());
    std::cout << "Using generic template SortData()" << std::endl;
};

class Person
{
public:
    Person(const std::string& name, const int age)
        : name(name), age(age) {}
    
    std::string getName() const { return name; }
    int getAge() const { return age; }

private:
    std::string name;
    int age;
};

// template specialization
template <>
void SortData(std::vector<Person>& data)
{
    std::sort(data.begin(), data.end(), [](const Person& a, const Person& b)
    {
        return a.getAge() < b.getAge(); // sort by age when using Person type
    });
    std::cout << "Using template specialization SortData() for Person objects" << std::endl;
};

// function template
template <typename T>
void PrintVector(const std::vector<T>& data)
{
    for (const auto& element : data)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
};

int main()
{
    std::vector<int> numbers{ 5, 2, 8, 1, 6 };
    SortData(numbers);
    PrintVector(numbers);

    std::vector<Person> people
    {
        Person("Alice", 25),
        Person("Bob", 30),
        Person("Charlie", 20)
    };
    SortData(people);
    for (const auto& person : people)
    {
        std::cout << person.getName() << " " << person.getAge() << std::endl;
    }

    return 0;
}