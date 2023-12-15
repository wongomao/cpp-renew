#include <iostream>
#include <random>

int random(int min, unsigned int max) {
    // random number generator
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased
    return uni(rng);
}

std::string get_item_name(int item)
{
    switch (item)
    {
    case 0:
        return "ROCK";
    case 1:
        return "PAPER";
    case 2:
        return "SCISSORS";
    default:
        return "INVALID";
    }
}

int main()
{
    while (true)
    {
        int computer_pick = random(0, 2);
        
        std::cout << "Pick 1 (ROCK), 2 (PAPER), or 3 (SCISSORS): ";
        int choice{};
        std::cin >> choice;
        if (choice < 1 || choice > 3)
        {
            std::cout << "Invalid choice.  Please try again." << std::endl;
            continue;
        }
        choice -= 1;

        std::cout << "Computer picked " << get_item_name(computer_pick) << std::endl;
        if (choice == computer_pick)
        {
            std::cout << "It's a tie! We each picked " << get_item_name(choice) << std::endl;
        }
        else if (choice == 1 && computer_pick == 2) // person picks paper, computer picks scissors
        {
            std::cout << "You lose! Your " << get_item_name(choice) << " is cut by my " << get_item_name(computer_pick) << "." << std::endl;
        }
        else if (choice == 1 && computer_pick == 0) // person picks paper, computer picks rock
        {
            std::cout << "You win! Your " << get_item_name(choice) << " covers my " << get_item_name(computer_pick) << "" << std::endl;
        }
        else if (choice == 2 && computer_pick == 1) // person picks scissors, computer picks paper
        {
            std::cout << "You win! Your " << get_item_name(choice) << " cuts my " << get_item_name(computer_pick) << "." << std::endl;
        }
        else if (choice == 2 && computer_pick == 0) // person picks scissors, computer picks rock
        {
            std::cout << "You lose! Your " << get_item_name(choice) << " is broken by my " << get_item_name(computer_pick) << "." << std::endl;
        }
        else if (choice == 0 && computer_pick == 1) // person picks rock, computer picks paper
        {
            std::cout << "You lose! Your " << get_item_name(choice) << " is covered by my " << get_item_name(computer_pick) << "." << std::endl;
        }
        else if (choice == 0 && computer_pick == 2) // person picks rock, computer picks scissors
        {
            std::cout << "You win! Your " << get_item_name(choice) << " breaks my " << get_item_name(computer_pick) << "." << std::endl;
        }



        std::cout << "Would you like to play again (y/n)? ";
        char c{};
        std::cin >> c;
        if (c == 'n')
        {
            std::cout << "Thanks for playing!" << std::endl;
            break;
        }
        else if (c == 'y')
        {
            std::cout << "OK, let's play again!" << std::endl;
            continue;
        }
        else
        {
            std::cout << "Oops, that input is invalid.  Please try again." << std::endl;
            continue;
        }
    }
    
}