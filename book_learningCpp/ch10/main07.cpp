#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // needed for std::remove_if

// Notice that we cannot create an instance of an abstract class
// due to the pure virtual method getGradeLevel()
// But we can create a vector of pointers to Pupil objects
// and add pointers to objects of derived classes
class Pupil
{
protected:
    std::string name;
    int age;
public:
    Pupil(const std::string &name, int age) : name(name), age(age) {}
    virtual std::string getGradeLevel() const = 0; // pure virtual method, abstract class
    void displayInfo() const // non-abstract function
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Grade Level: " << getGradeLevel() << std::endl;
        std::cout << std::endl;
    }
    std::string getName() const
    {
        return name;
    }
};

class Kindergarten : public Pupil
{
public:
    Kindergarten(const std::string &name, int age) : Pupil(name, age) {}

    std::string getGradeLevel() const override
    {
        return "Kindergarten";
    }
};

class ELementarySchool : public Pupil
{
private:
    int grade;
public:
    ELementarySchool(const std::string &name, int age, int grade) : Pupil(name, age), grade(grade) {}

    std::string getGradeLevel() const override
    {
        return "Elementary School - Grade " + std::to_string(grade);
    }
};

class MiddleSchool : public Pupil
{
private:
    int grade;
public:
    MiddleSchool(const std::string &name, int age, int grade) : Pupil(name, age), grade(grade) {}

    std::string getGradeLevel() const override
    {
        return "Middle School - Grade " + std::to_string(grade);
    }
};

int main()
{
    std::vector<Pupil*> pupils; // a collection of pointers to Pupil objects

    pupils.push_back(new Kindergarten("Sally", 5));
    pupils.push_back(new ELementarySchool("Thomas", 8, 3));
    pupils.push_back(new MiddleSchool("Jane", 12, 7));

    for (const auto& pupil : pupils)
    {
        pupil->displayInfo();
    }

    for (const auto& pupil : pupils)
    {
        delete pupil;
    }

    return 0;
}