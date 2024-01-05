#include <iostream>
#include <map>
#include <string>
#include <algorithm>

bool compare_no_case(std::wstring str1, std::wstring str2)
{
    std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    return (str1 == str2);
}

void add_capital(std::map<std::wstring, std::wstring>& Capitals,
    std::wstring country, std::wstring capital)
{
    Capitals.insert(std::make_pair(country, capital));
    // could also use Capitals[country] = capital;
    // could also use Capitals.insert(std::pair<std::wstring, std::wstring>(country, capital));
}

int main()
{
    std::map<std::wstring, std::wstring> Capitals;
    std::wstring input{ L"" }, output{ L"" };

    Capitals.insert(std::make_pair(L"France", L"Paris"));
    Capitals.insert(std::make_pair(L"Japan", L"Tokyo"));
    Capitals.insert(std::make_pair(L"Russia", L"Moscow"));
    Capitals.insert(std::make_pair(L"India", L"New Delhi"));
    Capitals.insert(std::make_pair(L"China", L"Beijing"));
    Capitals.insert(std::make_pair(L"Germany", L"Berlin"));

    std::wcout << L"Enter a country and I will tell you its capital." << std::endl;
    std::wcout << L"Enter 'q' to quit" << std::endl;
    std::wcin >> input;
    while (input != L"q")
    {
        std::map<std::wstring, std::wstring>::iterator it = Capitals.begin();
        bool found{ false };

        while (it != Capitals.end())
        {
            if (compare_no_case(it->first, input))
            {
                std::wcout << L"The capital of " << input.c_str();
                std::wcout << L" is " << it->second.c_str() << std::endl;
                found = true;
                break;
            }
            it++;
        }
        if (!found)
        {
            std::wcout << L"Sorry. I don't know the capital of " << input.c_str();
            std::wcout << L" Please tell me: " << std::endl;
            std::wstring new_capital{ L"" };
            std::wcin >> new_capital;
            add_capital(Capitals, input, new_capital);
            std::wcout << L"Now I know that the capital of " << input.c_str();
            std::wcout << L" is " << new_capital << std::endl;
        }

        std::wcout << L"Enter a country and I will tell you its capital." << std::endl;
        std::wcout << L"Enter 'q' to quit" << std::endl;
        std::wcin >> input;
    }
}