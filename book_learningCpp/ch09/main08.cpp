#include <iostream>
#include <string>
#include <vector>

struct flat
{
    std::wstring Apartment;
    std::wstring Tenant;
};

// AddResident() function takes a pointer to a vector of flat structs
// and two strings, and returns an integer of the size of the vector
int AddResident(std::vector<flat> *info, std::wstring Apartment, std::wstring Tenant)
{
    if (info == nullptr)
    {
        return 0;
    }
    flat newFlat;
    newFlat.Apartment = Apartment;
    newFlat.Tenant = Tenant;
    info->insert(info->end(), newFlat); // add newFlat to the end of the vector
    return info->size();
}

void PrintBuildingInfo(std::vector<flat> *info)
{
    for (int i = 0; i < info->size(); i++)
    {
        flat temp;
        temp = info->at(i);
        std::wcout << L"Resident " << i << std::endl;
        std::wcout << L"\tApartment: " << temp.Apartment << std::endl;
        std::wcout << L"\tTenant: " << temp.Tenant << std::endl;
    }
}

int main()
{
    // new std::vector<flat> creates a vector of flat structs on the heap
    // and returns a pointer to it
    std::vector<flat> *MyBuilding = new std::vector<flat>;
    int ID = AddResident(MyBuilding, L"Apartment A1", L"John");
    ID = AddResident(MyBuilding, L"Apartment A2", L"James");
    ID = AddResident(MyBuilding, L"Apartment B1", L"Thomas");

    PrintBuildingInfo(MyBuilding);
    // does delete MyBuilding delete all the structs in the vector?
    // yes - but if each element of the vector is/has a pointer, then we need to
    // delete each element of the vector first, then delete the vector
    delete MyBuilding; // delete the vector from the heap
    MyBuilding = nullptr; // set the pointer to nullptr

    return EXIT_SUCCESS;
}