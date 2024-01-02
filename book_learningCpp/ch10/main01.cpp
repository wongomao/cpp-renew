#include <iostream>

// see the c++ guidelines here: https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md

class Animal
{
public:
    std::string name;
    int age;
    std::string color;
    static int count;

    // default constructor
    // good practice is to have one constructor with the most parameters and
    // have other constructors call it with default values
    // This ':' notation is called a `constructor initialization list`
    Animal() : Animal("Unknown", 0, "White") {}

    // parameterized constructor
    Animal(const std::string &name, int age, const std::string &color)
        : name(name), age(age), color(color) // initialization list
    {
        count++;
    }

    Animal(const Animal &other) // copy constructor
        : name(other.name), age(other.age), color(other.color)
    {
        count++;
    }

    void eat()
    {
        std::cout << name << " is eating." << std::endl;
    }
 
    void sleep()
    {
        std::cout << name << " is sleeping quietly." << std::endl;
    }

    void displayInfo()
    {
        std::cout << "Name: " << name;
        std::cout << "\tAge: " << age;
        std::cout << "\tColor: " << color << std::endl;
    }

    static void displayCount()
    {
        std::cout << "\tCount: " << count << std::endl;
    }

    ~Animal() // destructor
    {
        count--;
        std::cout << "Destroying animal: " << name << std::endl;
        displayCount();
    }
};

int Animal::count = 0;

int main()
{
    // create an object on the heap - default constructor
    Animal *lion = new Animal();
    lion->name = "Leo the lion";
    lion->age = 5;
    lion->color = "Golden";
    lion->displayInfo();

    lion->sleep();
    lion->eat();

    // Animal::count++; // access static member variable
    Animal::displayCount(); // access static member function

    Animal tiger; // create an object on the stack
    tiger.name = "Tigger the tiger";
    tiger.age = 3;
    tiger.color = "Orange";
    tiger.displayInfo();
    tiger.sleep();

    // create an object on the heap - parameterized constructor
    Animal *monkey = new Animal("Mike the monkey", 2, "Brown"); 
    monkey->displayInfo();
    monkey->eat();
    delete monkey;

    // delete tiger; // error: stack object cannot be deleted
    delete lion;
 
    return 0;
}
 