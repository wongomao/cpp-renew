#include <iostream>
#include <string>

class Animal
{
    friend class Veterinary;

private:
    std::string name;
    int age;
    std::string color;
    bool isVaccinated;

public:
    Animal(const std::string& animalName, int animalAge, const std::string& animalColor)
        :
        name(animalName),
        age(animalAge),
        color(animalColor),
        isVaccinated(false)
    {}

    void displayInfo()
    {
        std::cout << "Name: " << name;
        std::cout << ", Age: " << age;
        std::cout << ", Color: " << color;
        std::cout << "Vaccinated: " << (isVaccinated ? "Yes" : "No") << std::endl;
    
    }
};

class Veterinary
{
public:
    void examineAnimal(Animal& animal)
    {
        // Friend class can access private members of Animal
        std::cout << "Performing medical examination on " << animal.name << std::endl;
        std::cout << "Age: " << animal.age << std::endl;
        std::cout << "Color: " << animal.color << std::endl;
        animal.isVaccinated = true;
        std::cout << "Animal is now vaccinated." << std::endl;
    }
};

int main()
{
    Animal lion("Simba", 5, "golden");
    lion.displayInfo();

    Veterinary vet;
    vet.examineAnimal(lion);

    lion.displayInfo();
}