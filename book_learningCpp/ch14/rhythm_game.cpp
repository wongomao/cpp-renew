#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>
#include <thread>

#ifdef _WIN32
#include <conio.h>
#include <Windows.h> // WinApi header
#else
#include <unistd.h>
#endif

constexpr int BEEP_FREQUENCY = 800;
constexpr int QUARTER_NOTE_DURATION = 400;
char get_single_key()
{
#ifdef _WIN32
    return _getch();
#else
    char ch;
    read(STDIN_FILENO, &ch, 1);
    return ch;
#endif
}

void flash_char(char ch, int duration)
{
    auto start_time = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start_time).count() < duration)
    {
        std::cout << ch;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "\b \b";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void play_sound(int frequency, int duration)
{
    Beep(frequency, duration);
    // for (int i = 0; i < duration; i += 100)
    // {
    //     std::cout << '\a';
    //     std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // }
}

void play_rhythm(const std::vector<int>& rhythm)
{
    for (int duration : rhythm)
    {
        flash_char('*', duration);
        play_sound(BEEP_FREQUENCY, duration);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

std::vector<int> generate_rhythm(std::mt19937& generator, std::uniform_int_distribution<int>& rhythmDistribution)
{
    std::vector<int> rhythm;
    const int numberOfNotes = 5;
    for (int i = 0; i < numberOfNotes; ++i)
    {
        int duration = rhythmDistribution(generator) * (QUARTER_NOTE_DURATION / 4);
        rhythm.emplace_back(duration);
    }
    return rhythm;
}

void repeat_rhythm(const std::vector<int>& rhythm, std::vector<std::chrono::milliseconds>& userRhythm)
{
    std::cout << "Repeat the rhythm by pressing any key." << std::endl;
    for (int i = 0; i < rhythm.size(); ++i)
    {
        get_single_key();
        play_sound(BEEP_FREQUENCY, 200);
        std::cout << "!" << "\b \b";
        std::cout.flush();
 
        auto currentTime = std::chrono::high_resolution_clock::now();
        userRhythm.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - currentTime));
    }
}

int calculate_score(const std::vector<int>& rhythm, const std::vector<std::chrono::milliseconds>& userRhythm)
{
    int score = 0;
    for (int i = 0; i < rhythm.size(); ++i)
    {
        int difference = static_cast<int>((rhythm[i] - userRhythm[i].count()) / 10);
        score += 100 - std::min<int>(100, std::abs(difference));
    }
    score /= rhythm.size();
    return score;
}

void OptionsMenu(char& option)
{
    std::cout << "Options:\n";
    std::cout << "1 - Try again\n";
    std::cout << "2 - Play another rhythm\n";
    std::cout << "3 - Quit\n";
    std::cout << "Enter your choice: ";
 
    option = get_single_key();
}

int main()
{
    std::cout << "Welcome to the Rhythm Game!" << std::endl;

    bool playAgain = true;
    char option;
    std::vector<int> rhythm;
    std::vector<std::chrono::milliseconds> userRhythm;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> rhythmDistribution(2, 4);

    while (playAgain)
    {
        std::cout << "Press any key to start..." << std::endl;
        get_single_key();

        rhythm = generate_rhythm(generator, rhythmDistribution);
        std::cout << "Listen to the rhythm:" << std::endl;
        play_rhythm(rhythm);

        userRhythm.clear();
        repeat_rhythm(rhythm, userRhythm);

        int score = calculate_score(rhythm, userRhythm);
        std::cout << "\nYour score is: " << score << " out of 100" << std::endl;

        OptionsMenu(option);

        switch (option)
        {
        case '1':
            repeat_rhythm(rhythm, userRhythm);
            score = calculate_score(rhythm, userRhythm);
            std::cout << "\nYour score is: " << score << " out of 100" << std::endl;
            OptionsMenu(option);
            break;
        case '2':

            rhythm = generate_rhythm(generator, rhythmDistribution);
            break;
        case '3':
            playAgain = false;
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            OptionsMenu(option); 
            break;
        }
    }

    return 0;
}