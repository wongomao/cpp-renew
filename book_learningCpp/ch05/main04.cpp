#include <iostream>

const int ROWS = 10;
const int COLS = 10;
int spreadsheet[ROWS][COLS]{};

inline void printSpreadsheet(int spreadsheet[ROWS][COLS])
{
    const char *SEPARATOR = "\t";
    std::cout << SEPARATOR;
    for (char col = 'A'; col < 'A' + COLS; ++col)
    {
        std::cout << col << SEPARATOR;
    }
    std::cout << std::endl;

    for (int row = 0; row < ROWS; ++row)
    {
        std::cout << row + 1 << SEPARATOR;
        for (int col = 0; col < COLS; ++col)
        {
            std::cout << spreadsheet[row][col] << SEPARATOR;
        }
        std::cout << std::endl;
    }
}

inline int& cell(char col, int row)
{
    return spreadsheet[row - 1][col - 'A'];
}

int main()
{
    cell('D', 4) = 99;
    cell('I', 10) = 30;
    cell('F', 2) = 19;
    cell('G', 5) = 93;
    cell('A', 4) = 12;

    // use column J for the sum of each row
    for (int row = 0; row < ROWS; ++row)
    {
        int sum = 0;
        for (int col = 0; col < COLS; ++col)
        {
            sum += spreadsheet[row][col];
        }
        cell('J', row + 1) = sum;
    }

    printSpreadsheet(spreadsheet);

    return 0;
}