#include <iostream>
#include <string>

// struct is a user-defined type
struct flat
{
    std::wstring Apartment;
    std::wstring Tenant;
};

int main()
{
    flat myFlat;
    myFlat.Apartment = L"Apartment 1";
    myFlat.Tenant = L"John Doe";

    std::wcout << L"Apartment: " << myFlat.Apartment << std::endl;
    std::wcout << L"Tenant: " << myFlat.Tenant << std::endl;

    // working with pointers to structs, we can use the arrow operator
    // to access the members of the struct
    flat *pFlat = &myFlat;
    pFlat->Apartment = L"Apartment 2"; // dereference the pointer and access the member
    pFlat->Tenant = L"Jane Doe"; // dereference the pointer and access the member
    std::wcout << L"Apartment: " << pFlat->Apartment << std::endl;
    std::wcout << L"Tenant: " << pFlat->Tenant << std::endl;
    // same as:
    (*pFlat).Apartment = L"Apartment 3";
    (*pFlat).Tenant = L"John Smith";

    return 0;
}
