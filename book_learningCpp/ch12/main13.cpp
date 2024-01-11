#include <iostream> 
#include <concepts> 

// concept definition named 'has_get_size'
template <typename T>
concept has_get_size = requires(T obj)
{
    // requires that T has a member function named 'getSize'
    { obj.getSize() } -> std::same_as<int>;
};

// Definition of a template class named 'Container'
// Ensures that the template parameter T has a member function named 'getSize'
template <typename T>
    requires has_get_size<T>
class Container
{
public:
    void printSize(const T& obj)
    {
        std::cout << "Size: " << obj.getSize() << std::endl;
    }
};

// definition of an animal class that has a member function named 'getSize'
// that returns an int
class Animal
{
public:
    int getSize() const
    {
        return 42;
    }
};

// definition of a plant class that has a member function named 'getSize'
// but it returns a double
class Plant
{
public:
    double getSize() const
    {
        return 3.14;
    }
};

int main()
{
    Container<Animal> animalContainer;
    Animal animal;
    animalContainer.printSize(animal);

    // This will not compile because the plant class has a member function
    // named 'getSize' but it returns a double instead of an int
    // Container<Plant> plantContainer;
    // Plant plant;
    // plantContainer.printSize(plant);

    return 0;
}