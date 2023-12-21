#include <iostream>
#include <string>
#include <algorithm> // for std::transform

typedef enum
{
    Month,
    City
} Element; // newly created type Element; an Element can be either a Month or a City

const int numMonths{ 12 };
const int numCities{ 4 };
std::wstring TemperaturesInCities[numCities+1][numMonths+1] =
{
    {L"", L"Jan", L"Feb", L"Mar", L"Apr", L"May", L"Jun", L"Jul",L"Aug", L"Sep", L"Oct", L"Nov", L"Dec"},
    {L"New York", L"2", L"4", L"0",  L"8",  L"12", L"18", L"27", L"28", L"31", L"19", L"7", L"1"},
    {L"London", L"8", L"3", L"10", L"12", L"19", L"22", L"25", L"29", L"18", L"15", L"7", L"5"},
    {L"Barcelona", L"10",L"9", L"15", L"20", L"25", L"27", L"30", L"33", L"25", L"12", L"10",L"8"},
    {L"Paris", L"0", L"3", L"10", L"15", L"19", L"21", L"27", L"31", L"20", L"13", L"4", L"0"}
};

std::wstring GET_CITY_NAME(int index)
{
    return TemperaturesInCities[index][0];
}

std::wstring GET_MONTH_NAME(int index)
{
    return TemperaturesInCities[0][index];
}

inline void SetLower(std::wstring &str)
{
    std::transform(str.begin(), str.end(), str.begin(), towlower);
}

/*
GetData returns the index of the month or city in the array TemperaturesInCities.
*/
int GetData(std::wstring input, Element element)
{
    bool found{ false };
    int result{ -1 };
    SetLower(input);
    switch (element)
    {
    case Month: // search for month in first row of TemperaturesInCities
    {
        for (int i = 1; i < numMonths+1; i++)
        {
            std::wstring temp = TemperaturesInCities[0][i];
            SetLower(temp);

            if (input == temp)
            {
                found = true;
                result = i;
                break;
            }
        }
    }
    break;
    case City:  // search for city in first column of TemperaturesInCities
    {
        for (int i = 1; i < numCities+1; i++)
        {
            std::wstring temp = TemperaturesInCities[i][0];
            SetLower(temp);

            if (temp == input)
            {
                found = true;
                result = i;
                break;
            }
        }
    }
    break;
    
    default:
        break;
    }

    return result;
}

int main()
{
    std::wstring city;
    std::wstring month;
    int cityIndex{ -1 };
    int monthIndex{ -1 };
    bool bShouldRun{ true };
    while (bShouldRun)
    {
        std::wcout << L"Please enter a city: " << std::endl;
        std::getline(std::wcin, city);
        cityIndex = GetData(city, City);
        if (cityIndex != -1) break; // disallow a non-found city
        std::wcout << L"City " << city << L" not found." << std::endl;
        bShouldRun = false;
    }
    while (bShouldRun)
    {
        std::wcout << L"Please enter the month in which you wish to get the temperatures in ";
        std::wcout << city << ": " << std::endl;
        std::wcin >> month;
        monthIndex = GetData(month, Month);
        if (monthIndex != -1) break; // disallow a non-found month
        std::wcout << L"Month " << month << L" not found. " << std::endl;
        bShouldRun = false;
    }
    if (bShouldRun)
    {
        std::wcout << L"The average temperature in ";
        std::wcout << GET_CITY_NAME(cityIndex) << L" during ";
        std::wcout << GET_MONTH_NAME(monthIndex) << L" is ";
        std::wcout << TemperaturesInCities[cityIndex][monthIndex] << L" degrees C.";
        std::wcout << std::endl;
    }
}
/* Output:
Please enter a city: 
London
Please enter the month in which you wish to get the temperatures in London:
Oct
The average temperature in London during Oct is 15 degrees C.
*/