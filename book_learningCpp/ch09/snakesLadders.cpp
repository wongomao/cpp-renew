#include <iostream>
#include <chrono>
#include <random>

void movePlayer(int& position, int steps)
{
    position += steps;
}

bool checkWin(int position, int target)
{
    return (position >= target);
}

int throwDice()
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    // Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits.
    // Mersenne Twister is a popular pseudorandom number generator (PRNG). 
    // Named after the Mersenne prime numbers and is part of the <random>
    // header file and the std::mt19937 class.
    std::mt19937 generator(seed);
    // evenly distributed results in the range [1, 6] (inclusive)
    std::uniform_int_distribution<int> distribution(1, 6);
    return distribution(generator);
}

void checkEncounters(int &position, 
    const std::shared_ptr<std::array<int, 10>> snakes,
    const std::shared_ptr<std::array<int, 10>> ladders,
    const std::shared_ptr<std::array<int, 10>> ladderTargets,
    const std::string& playerType)
{
    for (int i = 0; i < 10; ++i)
    {
        if (position == (*snakes)[i])
        {
            int newPosition = position - 10;
            if (newPosition < 5)
            {
                newPosition = 5;
            }
            std::cout << "Oops! " << playerType << " encountered a snake and moves back to position " << newPosition << "." << std::endl;
            position = newPosition;
            break;
        }
        else if (position == (*ladders)[i])
        {
            std::cout << "Great! " << playerType << " encountered a ladder and moves ahead to position " << (*ladderTargets)[i] << "." << std::endl;
            position = (*ladderTargets)[i];
            break;
        }
    }
}


int main()
{
    int playerPosition{ 0 };
    int computerPosition{ 0 };
    const int targetPosition{ 100 };

    // int snakes[]{ 16, 47, 49, 56, 62, 64, 87, 93, 95, 98 };
    // int ladders[]{ 1, 4, 9, 21, 28, 36, 51, 71, 80, 87 };
    // int ladderTargets[]{ 5, 14, 31, 38, 84, 44, 67, 91, 100, 93 };
    std::shared_ptr<std::array<int, 10>> snakes =
        std::make_shared<std::array<int, 10>>(std::array<int, 10>
            { 16, 47, 49, 56, 62, 64, 87, 93, 95, 98 });
    std::shared_ptr<std::array<int, 10>> ladders =
        std::make_shared<std::array<int, 10>>(std::array<int, 10>
            { 1, 4, 9, 21, 28, 36, 51, 71, 80, 87 });
    std::shared_ptr<std::array<int, 10>> ladderTargets =
        std::make_shared<std::array<int, 10>>(std::array<int, 10>
            { 5, 14, 31, 38, 84, 44, 67, 91, 100, 93 });
    
    std::cout << "Welcome to Snakes and Ladders!" << std::endl;
    std::cout << "You need to reach the target position (" << targetPosition << ") to win." << std::endl;

    while (!checkWin(playerPosition, targetPosition) && !checkWin(computerPosition, targetPosition))
    {
        std::cout << "Press Enter to throw the dice." << std::endl;
        std::cin.get();

        int playerSteps = throwDice();
        int computerSteps = throwDice();

        movePlayer(playerPosition, playerSteps);
        movePlayer(computerPosition, computerSteps);

        checkEncounters(playerPosition, snakes, ladders, ladderTargets, "Player");
        checkEncounters(computerPosition, snakes, ladders, ladderTargets, "Computer");

        std::cout << "Player position: " << playerPosition << std::endl;
        std::cout << "Computer position: " << computerPosition << std::endl;

        if (checkWin(playerPosition, targetPosition))
        {
            std::cout << "Congratulations! You won!" << std::endl;
        }
        else if (checkWin(computerPosition, targetPosition))
        {
            std::cout << "Computer won!" << std::endl;
        }
    }

    snakes.reset();
    ladders.reset();
    ladderTargets.reset();

    return 0;
}