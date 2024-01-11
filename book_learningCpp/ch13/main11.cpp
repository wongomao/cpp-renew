/*
Use Dynamic Programming and Knapsack Problem to solve the playlist
from library. The random shuffle was used in main10.cpp, and we will
use the same library.

We use a table dp of size (library.size() + 1) x (run_duration + 1) to
store the maximum duration of songs that can be played in the run.
Each cell dp[i][j] represents the maximum duration achievable using the 
first i songs and a maximum duration of j.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <numeric>

struct Song
{
    std::string title;
    std::string artist;
    double duration;
};

std::vector<Song> generateLibrary()
{
    std::vector<Song> library =
    {
        {"Bohemian Rhapsody", "Queen", 5.55},
        {"Stairway to Heaven", "Led Zeppelin", 8.02},
        {"Shine On You Crazy Diamond", "Pink Floyd", 13.30},
        {"Knockin' On Heaven's Door", "Guns N' Roses", 5.36},
        {"Lingus", "Snarky Puppy", 10.26},
        {"What About Me", "Snarky Puppy", 6.32},
        {"Hotel California", "The Eagles", 6.30},
        {"Sweet Child O' Mine", "Guns N' Roses", 5.55},
        {"Hey Jude", "The Beatles", 7.06},
        {"November Rain", "Guns N' Roses", 8.57},
        {"Free Bird", "Lynyrd Skynyrd", 9.08},
        {"Let It Be", "The Beatles", 4.03},
        {"Bohemian Rhapsody", "Bad News", 3.30},
        {"Don't Stop Believin'", "Journey", 4.11},
        {"Bohemian Rhapsody", "The Braids", 6.02},
        {"Livin' On A Prayer", "Bon Jovi", 4.11},
        {"Sultans Of Swing", "Dire Straits", 5.50},
        {"Sweet Home Alabama", "Lynyrd Skynyrd", 4.45},
        {"Thunderstruck", "AC/DC", 4.52},
        {"Back In Black", "AC/DC", 4.15},
        {"Whole Lotta Rosie", "AC/DC", 5.23},
        {"I Want To Break Free", "Queen", 4.18},
        {"Another One Bites The Dust", "Queen", 3.36},
        {"Under Pressure", "Queen", 4.04},
        {"We Will Rock You", "Queen", 2.01},
        {"We Are The Champions", "Queen", 3.00}
    };
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(library.begin(), library.end(), generator);
    return library;
}

std::vector<Song> generatePlaylist(const std::vector<Song>& library, double desired_duration)
{
    std::vector<Song> playlist;
    // create a table 'dp' to store the maximum duration achievable for
    // different subsets of songs and desired durations.
    std::vector<std::vector<double>> dp(library.size() + 1, std::vector<double>(desired_duration + 1, 0.0));

    // iterate over each song in the library
    for (int i = 1; i <= library.size(); ++i)
    {
        const Song& song = library[i - 1]; // current song

        for (int j = 1; j <= desired_duration; ++j) // iterate over each desired duration
        {
            // check if the current song can be included in the playlist for the given duration.
            if (song.duration <= j)
            {
                // calculate the maximum duration if the current song is included.
                double include_duration = song.duration + dp[i -1][j - static_cast<int>(song.duration)];
                // calculate the maximum duration if the current song is excluded.
                double exclude_duration = dp[i - 1][j];
                // take the maximum of the durations (include or exclued) and store it in the 'dp' table.
                dp[i][j] = std::max(include_duration, exclude_duration);
            }
            else
            {
                // if the current song cannot be included, take the value from
                // excluding the song.
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int i = library.size();
    int j = desired_duration;
    // backtrack to find the optimal subset of songs included in the playlist.
    while (i > 0 && j > 0)
    {
        // check if the inclusion of the current song leads to a higher duration.
        if (dp[i][j] != dp[i - 1][j])
        {
            // if the current song is included, add it to the playlist.
            playlist.push_back(library[i - 1]);
            // subtract the duration of the current song from the remaining desired duration.
            j -= static_cast<int>(library[i - 1].duration);
        }
        i--;
    }
    return playlist;
}

int main()
{
    const int MIN_RUN_DURATION = 15;
    const int MAX_RUN_DURATION = 90;
    const auto INVALID_DURATION = [&](int run_duration)
        {return run_duration < MIN_RUN_DURATION || run_duration > MAX_RUN_DURATION; };

    std::cout << "How long is your run? (Enter the duration in minutes between ";
    std::cout << MIN_RUN_DURATION << " and " << MAX_RUN_DURATION << "): ";

    int run_duration{ 0 }; // user input is an integer
    while (INVALID_DURATION(run_duration))
    {
        std::cin >> run_duration;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

        if (INVALID_DURATION(run_duration))
        {
            std::cout << "Invalid duration. Please enter a value between ";
            std::cout << MIN_RUN_DURATION << " and " << MAX_RUN_DURATION << ": ";
        }
    }
    double desired_duration = static_cast<double>(run_duration); // convert user input to double

    std::vector<Song> library = generateLibrary();
    std::vector<Song> playlist = generatePlaylist(library, desired_duration);

    // calculate the total duration of the playlist
    double total_duration = std::accumulate(playlist.begin(), playlist.end(), 0.0,
        [](double sum, const Song& s) {return sum + s.duration; });

    // subtract out songs from the playlist until the total duration is less than the desired duration
    while (total_duration > desired_duration)
    {
        // remove the last song from the playlist
        total_duration -= playlist.back().duration;
        playlist.pop_back();
    }

    // print the playlist
    std::cout << "-- Playlist --" << std::endl;
    for (const auto& song : playlist)
    {
        std::cout << song.title << " (" << song.artist << "): " << song.duration << std::endl;
    }
    std::cout << "Total duration: " << total_duration << std::endl;

    return 0;
}