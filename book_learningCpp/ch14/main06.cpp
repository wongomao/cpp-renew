#include <chrono>
#include <conio.h>
#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>
#include <vector>

/*
Note: this kind of line appears uncompilable:
std::cout << "\033[1;32m*\033[0m" << std::endl;

The solution is to use windows.h and SetConsoleTextAttribute().
    // how to do colors in windows:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);

    std::cout << "hi" << std::endl;

    SetConsoleTextAttribute(hConsole, 7);
*/

#ifdef _WIN32
#include <conio.h>
#define GETCH _getch()
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#else
#include <ncurses.h>
#define GETCH getch()
#define KEY_UP KEY_UP
#define KEY_DOWN KEY_DOWN
#define KEY_LEFT KEY_LEFT
#define KEY_RIGHT KEY_RIGHT
#endif

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class MazeGenerator
{
public:
    MazeGenerator(int rows, int cols)
        : rows(rows), cols(cols), maze(rows, std::vector<char>(cols, '#')),
        generator(rd())
    {}

    void generateMaze()
    {
        int startRow = 1;
        int startCol = 1;
        generateRecursive(startRow, startCol);
        maze[startRow][startCol] = 'S';
        maze[rows - 2][cols - 2] = 'E';
    }

    void printMaze() const
    {
        for (const auto& row : maze)
        {
            for (const auto& cell : row)
            {
                if (cell == '*')
                {
                    std::cout << "\033[1;32m" << cell << "\033[0m";
                }
                else
                {
                    std::cout << ' ';
                }
            }
            std::cout << '\n';
        }
    }

    void playMaze()
    {
        playerRow = 1;
        playerCol = 1;
        printMaze();
        while (true)
        {
            char input = GETCH;

            switch (input)
            {
            case KEY_UP:
                move(Direction::UP);
                break;
            case KEY_DOWN:
                move(Direction::DOWN);
                break;
            case KEY_LEFT:
                move(Direction::LEFT);
                break;
            case KEY_RIGHT:
                move(Direction::RIGHT);
                break;
            default:
                break;
            }

            moveCursorToPlayerPosition();
            printPlayerSymbol();

            if (playerRow == rows - 2 && playerCol == cols - 2 )
            {
                int messageRow = rows + 2;
                int messageCol = (cols * 2 + 1 - 39) / 2;

                std::cout << "\033[" << messageRow << ";" << messageCol << "H";
                std::cout << "\033[1;36mCongratulations! You reached the end "
                    "of the maze!\033[0m\n";
                break;
            }
        }
    }

private:
    std::random_device rd;
    std::mt19937 generator;
    int rows;
    int cols;
    std::vector<std::vector<char>> maze;
    int playerRow;
    int playerCol;
    int prevPlayerRow;
    int prevPlayerCol;

    void generateRecursive(int row, int col)
    {
        maze[row][col] = ' ';
        std::vector<Direction> directions = { Direction::UP, Direction::DOWN,
            Direction::LEFT, Direction::RIGHT };
        std::ranges::shuffle(directions, generator);

        for (const auto& direction : directions)
        {
            int newRow = row;
            int newCol = col;

            if (direction == Direction::UP)
            {
                newRow -= 2;
                if (newRow < 0)
                {
                    continue;
                }
                if (maze[newRow][col] != ' ')
                {
                    maze[newRow + 1][col] = ' ';
                    generateRecursive(newRow, col);
                }
            }
            else if (direction == Direction::DOWN)
            {
                newRow += 2;
                if (newRow >= rows)
                {
                    continue;
                }
                if (maze[newRow][col] != ' ')
                {
                    maze[newRow - 1][col] = ' ';
                    generateRecursive(newRow, col);
                }
            }
            else if (direction == Direction::LEFT)
            {
                newCol -= 2;
                if (newCol < 0)
                {
                    continue;
                }
                if (maze[row][newCol] != ' ')
                {
                    maze[row][newCol + 1] = ' ';
                    generateRecursive(row, newCol);
                }
            }
            else if (direction == Direction::RIGHT)
            {
                newCol += 2;
                if (newCol >= cols)
                {
                    continue;
                }
                if (maze[row][newCol] != ' ')
                {
                    maze[row][newCol - 1] = ' ';
                    generateRecursive(row, newCol);
                }
            }
        }
    }

    void move(Direction direction)
    {
        prevPlayerRow = playerRow;
        prevPlayerCol = playerCol;

        int newRow = playerRow;
        int newCol = playerCol;

        if (direction == Direction::UP)
        {
            newRow--;
        }
        else if (direction == Direction::DOWN)
        {
            newRow++;
        }
        else if (direction == Direction::LEFT)
        {
            newCol--;
        }
        else if (direction == Direction::RIGHT)
        {
            newCol++;
        }

        if (maze[newRow][newCol] == ' ' || maze[newRow][newCol] == 'E')
        {
            playerRow = newRow;
            playerCol = newCol;
        }
    }

    void moveCursorToPlayerPosition()
    {
        if (prevPlayerRow != playerRow || prevPlayerCol != playerCol)
        {
            std::cout << "\033[" << prevPlayerRow + 1 << ";"
                << prevPlayerCol * 2 + 1 << "H";
            std::cout << ' ';
        }
        std::cout << "\033[" << playerRow + 1 << ";"
            << playerCol * 2 + 1 << "H";
    }

    void printPlayerSymbol()
    {
        std::cout << "\033[1;32m*\033[0m";
    }
};

int main()
{
#ifndef _WIN32
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
#endif

    int rows = 21;
    int cols = 51;

    MazeGenerator mazeGenerator(rows, cols);
    mazeGenerator.generateMaze();
    mazeGenerator.printMaze();
    //mazeGenerator.playMaze();

#ifndef _WIN32
    endwin();
#endif
    return 0;
}