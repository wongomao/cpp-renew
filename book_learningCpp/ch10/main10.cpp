#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

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

void showList(const std::list<Pupil*>& pupils)
{
    for (const auto& pupil : pupils)
    {
        pupil->displayInfo();
    }
}

// FunctionObject
struct WeedOut
{
    bool operator()(Pupil* pupil) const
    {
        std::cout << "Checking " << pupil->getName() << std::endl;
        bool alphaGreaterThanM = pupil->getName()[0] > 'M';
        return alphaGreaterThanM;
    }
};

int main()
{
    std::list<Pupil*> pupils; // a collection of pointers to Pupil objects

    auto* p1 = new Kindergarten("Sally", 5);
    auto* p2 = new ELementarySchool("Thomas", 8, 3);
    auto* p3 = new MiddleSchool("Jane", 12, 7);
    auto* p4 = new MiddleSchool("Wentworth", 13, 8);
    auto* p5 = new ELementarySchool("Amanda", 7, 2);

    pupils.push_back(p1);
    pupils.push_back(p2);
    pupils.push_back(p3);
    pupils.push_back(p4);
    pupils.push_back(p5);
    
    showList(pupils);
    // WeedOut functor
    std::cout << "Weed out pupils whose name starts with a letter greater than M" << std::endl;
    for (std::list<Pupil*>::iterator it = pupils.begin(); it != pupils.end();)
    {
        if (WeedOut()(*it))
        {
            auto pupil = *it;
            std::cout << "Removing " << pupil->getName() << std::endl;
            it = pupils.erase(it);
        }
        else
        {
            it++;
        }
    }
    std::cout << "---------------------" << std::endl;
    showList(pupils);



    return 0;
}