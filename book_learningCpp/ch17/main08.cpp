#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

class Animal
{
public:
    Animal(const std::string& name) : m_name(name) {}
    virtual ~Animal() {};

    virtual void makeSound() const = 0;
    virtual void eat() const
    {
        std::cout << m_name << " is eating" << std::endl;
    }
    virtual void sleep() const
    {
        std::cout << m_name << " is sleeping" << std::endl;
    }
    std::string getName() const { return m_name; }
private:
    std::string m_name;
};

class Dog : public Animal
{
public:
    Dog(const std::string& name) : Animal(name) {}
    virtual void makeSound() const override
    {
        std::cout << "Woof!" << std::endl;
    }
};
class Cat : public Animal
{
public:
    Cat(const std::string& name) : Animal(name) {}
    virtual void makeSound() const override
    {
        std::cout << "Meow!" << std::endl;
    }
};
class Fish : virtual public Animal
{
public:
    Fish(const std::string& name) : Animal(name) {}
    virtual void makeSound() const override
    {
        throw std::runtime_error("Fish do not make sound");
    }
    virtual void eat() const override
    {
        std::cout << getName() << " is nibbling on some plants" << std::endl;
    }
};

class AnimalFactory
{
public:
    static Animal* createAnimal(const std::string& name, const std::string& type)
    {
        std::string typeLower = type;
        std::transform(typeLower.begin(), typeLower.end(), typeLower.begin(), ::tolower);
        if (typeLower == "dog")
        {
            return new Dog(name);
        }
        else if (typeLower == "cat")
        {
            return new Cat(name);
        }
        else if (typeLower == "fish")
        {
            return new Fish(name);
        }
        else
        {
            throw std::runtime_error("Invalid animal type");
        }
    }
};

int main()
{
    try
    {
        std::string animalType;
        std::string animalName;
        std::string action;

        std::cout << "Enter the type of animal you want to create (e.g. 'Dog', 'Cat', 'Fish'): ";
        std::cin >> animalType;
        std::cin.ignore(); // ignore the newline character in the input buffer

        std::cout << "Enter the name of the animal: ";
        std::getline(std::cin, animalName);

        Animal* animal = AnimalFactory::createAnimal(animalName, animalType);

        std::cout << "What do you want " << animalName << " to do? (e.g. 'makeSound', 'eat', 'sleep'): ";
        std::getline(std::cin, action);
        if (action == "makeSound")
        {
            animal->makeSound();
        }
        else if (action == "eat")
        {
            animal->eat();
        }
        else if (action == "sleep")
        {
            animal->sleep();
        }
        else
        {
            throw std::runtime_error("Invalid action");
        }

        delete animal;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}