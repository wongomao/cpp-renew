#include <iostream>
#include <windows.h>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#include <conio.h>

#define CLEAR_SCREEN system("cls")

enum class Color
{
    BROWN,
    MAGENTA,
    YELLOW,
    GRAY,
    BLUE,
    RED,
    DEFAULT
};

void setTextColor(Color color = Color::DEFAULT)
{
/*
    BROWN = 4,
    MAGENTA = 5,
    YELLOW = 6,
    GRAY = 8,
    BLUE = 9,
    RED = 12,
    DEFAULT = 15
*/
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (color == Color::DEFAULT)
    {
        SetConsoleTextAttribute(hConsole, 15);
    }
    else if (color == Color::BROWN)
    {
        SetConsoleTextAttribute(hConsole, 4);
    }
    else if (color == Color::MAGENTA)
    {
        SetConsoleTextAttribute(hConsole, 5);
    }
    else if (color == Color::YELLOW)
    {
        SetConsoleTextAttribute(hConsole, 6);
    }
    else if (color == Color::GRAY)
    {
        SetConsoleTextAttribute(hConsole, 8);
    }
    else if (color == Color::BLUE)
    {
        SetConsoleTextAttribute(hConsole, 9);
    }
    else if (color == Color::RED)
    {
        SetConsoleTextAttribute(hConsole, 12);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 15);
    }
    
    return;
}

Color getRandomColor()
{
    int randomColor = rand() % static_cast<int>(Color::DEFAULT) + 1;
    return static_cast<Color>(randomColor);
}

struct Pixel
{
    char character;
    Color color;
};

void displayMatrix(const std::vector<std::vector<Pixel>>& matrix)
{
    for (const auto& row : matrix)
    {
        for (const auto& pixel : row)
        {
            setTextColor(pixel.color);
            std::cout << pixel.character;
        }
        std::cout << std::endl;
    }
    setTextColor(); // default
}

std::vector<std::string> generateRandomImage()
{
    // ascii art - THIS NEEDS WORK -
    std::vector<std::vector<std::string>> images =
    {
        {" _______ ", "|A      |", "|       |", "|   o   |", "|       |", "|_______|"},
        {" _______ ", "|2      |", "|   o   |", "|       |", "|   o   |", "|_______|"},
        {" _______ ", "|3      |", "|   o   |", "|   o   |", "|   o   |", "|_______|"},
        {" _______ ", "|4      |", "| o   o |", "|       |", "| o   o |", "|_______|"},
        {" _______ ", "|5      |", "| o   o |", "|   o   |", "| o   o |", "|_______|"},
        {" _______ ", "|6      |", "| o   o |", "| o   o |", "| o   o |", "|_______|"},
        {" _______ ", "|7      |", "| o o o |", "|       |", "| o o o |", "|_______|"},
        {" _______ ", "|8      |", "| o o o |", "| o   o |", "| o o o |", "|_______|"},
        {" _______ ", "|9      |", "| o o o |", "| o o o |", "| o o o |", "|_______|"},
        {" _______ ", "|10     |", "| o o o |", "|o o o o|", "| o o o |", "|_______|"},
        {" _______ ", "|J      |", "|   o   |", "|   o   |", "| o   o |", "|_______|"},
        {" _______ ", "|Q      |", "|   o   |", "| o o o |", "| o   o |", "|_______|"},
        {" _______ ", "|K      |", "| o   o |", "| o o o |", "| o   o |", "|_______|"},
        {" _______ ", "|A      |", "|   /\\  |", "|  /__\\ |", "| /    \\ |", "|_______|"},
        {" _______ ", "|2      |", "| /\\ /\\|", "| \\/ \\|", "|       |", "|_______|"},
        {" _______ ", "|3      |", "|   /\\ |", "|       |", "|  \\/  |", "|_______|"},
        {" _______ ", "|4      |", "| /\\  /|", "|       |", "|\\/  \\|", "|_______|"},
        {" _______ ", "|5      |", "| /\\  /|", "|   /\\ |", "|\\/  \\|", "|_______|"},
        {" _______ ", "|6      |", "| /\\  /|", "| /\\  /|", "|\\/  \\|", "|_______|"},
        {" _______ ", "|7      |", "| /\\ /\\|", "|       |", "|  /\\  |", "|_______|"},
        {" _______ ", "|8      |", "| /\\ /\\|", "| /  \\ |", "|  \\/  |", "|_______|"},
        {" _______ ", "|9      |", "| /\\ /\\|", "|  /\\  |", "|  \\/  |", "|_______|"},
        {" _______ ", "|10     |", "|  /\\  |", "| /  \\ |", "|/____\\|", "|_______|"},
        {" _______ ", "|J      |", "|   /\\  |", "|  /  \\ |", "|/____\\ |", "|_______|"},
        {" _______ ", "|Q      |", "|   /\\ |", "|  /  \\|", "|/    \\|", "|_______|"},
        {" _______ ", "|K      |", "|   /\\ |", "|  /  \\|", "|/____\\|", "|_______|"},
        {" _______ ", "|A      |", "|  /\\  |", "| /__\\ |", "|/    \\|", "|_______|"},
        {" _______ ", "|2      |", "|  /\\  |", "| /_\\  |", "|/____\\|", "|_______|"},
        {" _______ ", "|3      |", "|  /\\  |", "| \\_/  |", "|/____\\|", "|_______|"},
        {" _______ ", "|4      |", "|  /\\  |", "| //_\\ |", "|/____\\|", "|_______|"},
        {" _______ ", "|5      |", "|  /\\  |", "| //_\\ |", "|/____\\|", "|_______|"},
        {" _______ ", "|6      |", "|  /\\  |", "| //_\\ |", "|/____\\|", "|_______|"},
        {" _______ ", "|7      |", "|  /\\  |", "| //_\\ |", "|/____\\|", "|_______|"},
        {" _______ ", "|8      |", "|  /\\  |", "| //_\\ |", "|/____\\|", "|_______|"},
        {" _______ ", "|9      |", "|  /\\  |", "| //_\\ |", "|/____\\|", "|_______|"},
        {" _______ ", "|10     |", "|  /\\  |", "| //_\\ |", "|/____\\|", "|_______|"},
        {" _______ ", "|J      |", "|  /\\  |", "| //_\\ |", "|/____\\|", "|_______|"},
        {" _______ ", "|Q      |", "|  /\\  |", "| //_\\ |", "|/____\\|", "|_______|"},
        {" _______ ", "|K      |", "|  /\\  |", "| //_\\ |", "|/____\\|", "|_______|"},
        {" _______ ", "|A      |", "|  _    |", "| | |   |", "| |_|   |", "|_______|"},
        {" _______ ", "|2      |", "|   _   |", "|  |_)  |", "|   /   |", "|_______|"},
        {" _______ ", "|3      |", "|   __  |", "|  |_ \\|", "|____/\\|", "|_______|"},
        {" _______ ", "|4      |", "|  |_ _||", "|   |   |", "|   |   |", "|_______|"},
        {" _______ ", "|5      |", "|  |__  |", "|     | |", "|  |__| |", "|_______|"},
        {" _______ ", "|6      |", "|  |__  |", "|  |__| |", "|  |__| |", "|_______|"},
        {" _______ ", "|7      |", "| |___  |", "|    / /|", "|   / / |", "|_______|"},
        {" _______ ", "|8      |", "|  /\\  |", "| /  \\ |", "| \\  / |", "|_______|"},
        {" _______ ", "|9      |", "|  /\\  |", "| |__|  |", "|   /   |", "|_______|"},
        {" _______ ", "|10     |", "|  /\\  |", "| |__)  |", "|____   |", "|_______|"},
        {" _______ ", "|J      |", "|    /\\|", "|   / / |", "|  / /  |", "|_/_____|"},
        {" _______ ", "|Q      |", "|    /\\|", "|   /  \\|", "|  |\\__|", "|_/_____|"},
        {" _______ ", "|K      |", "|   \\_/|", "|   / \\|", "|  |   \\|", "|_/_____|"}
    };

    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(images.begin(), images.end(), rng);
 
    std::vector<std::string> selectedImages;
 
    int randomIndex = rand() % images.size();
    const std::vector<std::string>& image = images[randomIndex];
    for (const std::string& line : image)
    {
        selectedImages.push_back(line);
    }
    images.erase(images.begin() + randomIndex);

    return selectedImages;
}

std::vector<std::vector<Pixel>>
composeCombinedImage(const std::vector<std::string>& image1,
    const std::vector<std::string>& image2,
    const std::vector<std::string>& image3,
    Color color1, Color color2, Color color3)
{
    // determine the maximum number of lines among the images
    int maxLines = std::max({ image1.size(), image2.size(), image3.size() });
    // determine the maximum width among the images
    int maxWidth = std::max({ image1[0].size(), image2[0].size(), image3[0].size() });
    std::vector<std::vector<Pixel>> combinedImage(maxLines);

    // add pixels from image1
    for (int i = 0; i < image1.size(); ++i)
    {
        for (char c: image1[i])
        {
            combinedImage[i].push_back({ c, color1 });
        }
        // add spaces to match the maximum width
        int spacesToAdd = maxWidth - image1[i].size();
        for (int j = 0; j < spacesToAdd; ++j)
        {
            combinedImage[i].push_back({ ' ', Color::DEFAULT });
        }
    }
    // add empty pixels to align with images 2 and 3
    for (int i = image1.size(); i < maxLines; ++i)
    {
        for (int j = 0; j < maxWidth; ++j)
        {
            combinedImage[i].push_back({ ' ', Color::DEFAULT });
        }
    }

    // add pixels from image2
    for (int i = 0; i < image2.size(); ++i)
    {
        for (char c : image2[i])
        {
            combinedImage[i].push_back({ c, color2 });
        }
        // add spaces to match the maximum width
        int spacesToAdd = maxWidth - image2[i].size();
        for (int j = 0; j < spacesToAdd; ++j)
        {
            combinedImage[i].push_back({ ' ', Color::DEFAULT });
        }
    }
    // add empty pixels to align with image 3
    for (int i = image2.size(); i < maxLines; ++i)
    {
        for (int j = 0; j < maxWidth; ++j)
        {
            combinedImage[i].push_back({ ' ', Color::DEFAULT });
        }
    }

    // add pixels from image3
    for (int i = 0; i < image3.size(); ++i)
    {
        for (char c : image3[i])
        {
            combinedImage[i].push_back({ c, color3 });
        }
        // add spaces to match the maximum width
        int spacesToAdd = maxWidth - image3[i].size();
        for (int j = 0; j < spacesToAdd; ++j)
        {
            combinedImage[i].push_back({ ' ', Color::DEFAULT });
        }
    }

    return combinedImage;
}

bool checkWin(const std::vector<std::string>& image1,
    const std::vector<std::string>& image2,
    const std::vector<std::string>& image3,
    Color color1, Color color2, Color color3)
{
    return (image1 == image2
        && image2 == image3
        && color1 == color2
        && color2 == color3);
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock

    std::cout << "Welcome to the Slot Machine Game!" << std::endl;
    std::cout << "Press any key to start..." << std::endl;
    bool playAgain = true;

    while (playAgain)
    {
        CLEAR_SCREEN;

        std::vector<std::string> image1 = generateRandomImage();
        std::vector<std::string> image2 = generateRandomImage();
        std::vector<std::string> image3 = generateRandomImage();

        Color color1 = getRandomColor();
        Color color2 = getRandomColor();
        Color color3 = getRandomColor();

        std::vector<std::vector<Pixel>> combinedImage =
            composeCombinedImage(image1, image2, image3, color1, color2, color3);
        displayMatrix(combinedImage);
        if (checkWin(image1, image2, image3, color1, color2, color3))
        {
            std::cout << "You win!" << std::endl;
            break;
        }
        else
        {
            std::cout << "You lose!" << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Play again? (y/n): ";
        char option = _getch();
        if (option == 'n')
        {
            playAgain = false;
        }
        else
        {
            playAgain = true;
        }
    }


    setTextColor(); // return to usual color
    return 0;
}