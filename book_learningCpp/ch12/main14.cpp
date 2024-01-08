#include <iostream> 
#include <concepts> 

template <typename T>
concept HasGetSize = requires(T obj)
{
    { obj.getSize() } -> std::same_as<int>;
};

// note here the use of the concept 'HasGetSize' instead of the requires clause
// however, it may be better to use the requires clause because it is more
// explicit
template <HasGetSize T>
class Container
{
public:
    void printSize(const T& obj)
    {
        std::cout << "Size: " << obj.getSize() << std::endl;
    }
};

class Animal
{
public:
    int getSize() const
    {
        return 42;
    }
};

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
 
    return 0;
}