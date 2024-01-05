#include <iostream>
#include <string>

class Animal
{
protected:
    std::string name;
public:
    Animal(const std::string& animalName) : name(animalName) {}

    // const member function is a function that does not modify the object for which it is called
    void makeSound() const
    {
        std::cout << "Animal " << name << " makes a sound." << std::endl;
    }
};

class Bird : public Animal
{
public:
    // Constructor for Bird class calls the constructor for Animal class during initialization
    Bird(const std::string& birdName) : Animal(birdName) {}

    void fly() const
    {
        std::cout << "Bird " << name << " flies." << std::endl;
    }

    void makeSound() const // overrides the makeSound() function in the base class
    {
        std::cout << "Bird " << name << " chirps." << std::endl;
    }
};

int main()
{
    Bird bird("Hawk");
    bird.fly();
    bird.makeSound();

    // we can treat a Bird object as an Animal object via a reference or pointer
    Animal& rAnimal = bird; // rAnimal is a reference to the Animal object bird
    rAnimal.makeSound(); // calls the makeSound() function in the Animal class

    Animal* pAnimal = &bird; // pAnimal is a pointer to the Animal object bird
    pAnimal->makeSound(); // calls the makeSound() function in the Animal class

    return 0;
}