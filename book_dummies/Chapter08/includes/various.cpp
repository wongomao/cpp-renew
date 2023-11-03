#include <iostream>


void action1() {
    int numberOfPotholes = 5325;
    std::cout << "Potholes: " << numberOfPotholes << std::endl;
    std::cout << "Potholes variable address: " << &numberOfPotholes << std::endl;
}

void action2() {
    int numberOfPotholes = 5325;
    std::cout << "Potholes: " << numberOfPotholes << std::endl;
    int *pNumberOfPotholes = &numberOfPotholes;
    *pNumberOfPotholes = 6000;
    std::cout << "Changed Potholes: " << *pNumberOfPotholes << std::endl;
}

void action3() {
    std::string aGoodMovie = "The Thing";
    std::string *pAGoodMovie = &aGoodMovie;
    int len = (*pAGoodMovie).length();
    std::cout << "The length of '" << *pAGoodMovie << "' is " << len << std::endl;
    for (int i = 0; i < (*pAGoodMovie).length(); i++) {
        std::cout << (*pAGoodMovie)[i] << ' ';
    }
    std::cout << std::endl;

    for (auto it = (*pAGoodMovie).begin(); it < (*pAGoodMovie).end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    int index = 0;
    for (std::string::iterator it = (*pAGoodMovie).begin(); it < (*pAGoodMovie).end(); it++) {
        std::cout << *it << index++ << ' ';
    }
    std::cout << std::endl;
}

void action4() {
    int *ptr = new int(73);
    //*ptr = 5;
    std::cout << *ptr << std::endl;
    std::cout << ptr << std::endl;
    delete ptr;
}

void action5() {
    std::string *ptr = new std::string;
    *ptr = "Hello";
    std::cout << *ptr << std::endl;
    std::cout << ptr << std::endl;
    delete ptr;
}