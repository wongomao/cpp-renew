#include <iostream>
#include <string>
#include <array>

using namespace std;

void show_array(array<array<wstring, 13>, 5> &arr)
{
    for (auto i : arr)
    {
        bool isFirst = true;
        for (auto j : i)
        {
            wcout << j << L"\t" << (j.length() < 7 && isFirst ? L"\t" : L"");
            isFirst = false;
        }
        wcout << endl;
    }
}

inline wstring GET_CITY_NAME(array<array<wstring, 13>, 5> &arr, int index)
{
    return arr[index][0];
}

inline wstring GET_MONTH_NAME(array<array<wstring, 13>, 5> &arr, int index)
{
    return arr[0][index];
}

int main()
{
    array<array<wstring, 13>, 5> cityMonthData = 
    {
        {
            {L"",           L"Jan", L"Feb", L"Mar", L"Apr", L"May", L"Jun", L"Jul", L"Aug", L"Sep", L"Oct", L"Nov", L"Dec"},
            {L"New York",   L"2", L"4", L"0",  L"8",  L"12", L"18", L"27", L"28", L"31", L"19", L"7", L"1"},
            {L"London",     L"8", L"3", L"10", L"12", L"19", L"22", L"25", L"29", L"18", L"15", L"7", L"5"},
            {L"Barcelona",  L"10",L"9", L"15", L"20", L"25", L"27", L"30", L"33", L"25", L"12", L"10",L"8"},
            {L"Paris",      L"0", L"3", L"10", L"15", L"19", L"21", L"27", L"31", L"20", L"13", L"4", L"0"}
        }
    };

    show_array(cityMonthData);
    wcout << GET_CITY_NAME(cityMonthData, 1) << endl;
    wcout << GET_MONTH_NAME(cityMonthData, 1) << endl;
}