#include <iostream>

/*
Demonstrating virtual methods - making sure that ONLY ONE SHARED
INSTANCE of class A in the hierarchy, even though both B and C
inherit from it
*/

class A
{
public:
    virtual void doSomething()
    {
        std::cout << "Doing something in Class A" << std::endl;
    }
};

class B : virtual public A
{
public:
    // notice that we can only override virtual methods
    void doSomething() override
    {
        std::cout << "Doing something in Class B" << std::endl;
    }
};

class C : virtual public A
{
public:
    void doSomething() override
    {
        std::cout << "Doing something in Class C" << std::endl;
    }
};

class D : public B, public C
{
public:
    void doSomething() override
    {

        A::doSomething();
    }
};

int main()
{
    D object;
 
    object.doSomething(); 
    return 0;
}