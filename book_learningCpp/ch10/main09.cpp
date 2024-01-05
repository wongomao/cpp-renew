#include <iostream>

// operator overloading

// abstract class, cannot instantiate
class Vehicle
{
public:
    virtual void displayInfo() const = 0; // pure virtual function
    virtual ~Vehicle() {} // needs override
};

class Car : public Vehicle
{
private:
    std::string brand;
    int year;
public:
    Car(const std::string& b, int y) : brand(b), year(y) {}

    void displayInfo() const override
    {
        std::cout << "Car: " << brand << ", Year: " << year << std::endl;
    }

    bool operator>(const Car& other) const
    {
        return year > other.year;
    }
};

class Motorcycle : public Vehicle
{
private:
    std::string brand;
    bool hasSidecar;
public:
    Motorcycle(const std::string& b, bool s) : brand(b), hasSidecar(s) {}

    void displayInfo() const override
    {
        std::cout << "Motorcycle: " << brand;
        std::cout << ", Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
    }

    Motorcycle operator+(const Motorcycle& other) const
    {
        std::string combinedBrand = brand + " " + other.brand;
        bool hasCombinedSidecar = hasSidecar || other.hasSidecar;
        return Motorcycle(combinedBrand, hasCombinedSidecar);
    }
};

int main()
{
    Car car1("Toyota", 2010);
    Car car2("Honda", 2015);
    Car car3("Ford", 2005);
    if (car1 > car2)
    {
        std::cout << "Car 1 is newer" << std::endl;
    }
    else
    {
        std::cout << "Car 2 is newer" << std::endl;
    }
    car1.displayInfo();
    car2.displayInfo();
    car3.displayInfo();
    std::cout << std::endl;

    Motorcycle motorcycle1("Yamaha", false);
    Motorcycle motorcycle2("Suzuki", true);
    motorcycle1.displayInfo();
    motorcycle2.displayInfo();
    Motorcycle combinedMotorcycle = motorcycle1 + motorcycle2;
    combinedMotorcycle.displayInfo();
    std::cout << std::endl;

}