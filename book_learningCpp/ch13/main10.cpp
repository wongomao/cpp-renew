#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

struct Song
{
    std::string title;
    std::string artist;
    double duration;
};

int main()
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
    std::vector<Song> playlist;
    double total_duration = 0.0;

    std::shuffle(library.begin(), library.end(), generator);
    // define a lambda expression to filter songs less than 6 minutes
    auto lambda = [](const Song& s) { return s.duration < 6.0; };
    // copy songs less than 6 minutes to playlist
    std::copy_if(library.begin(), library.end(), std::back_inserter(playlist), lambda);

    std::cout << "How long is your run? (Enter the duration in minutes): ";
    double run_duration;
    std::cin >> run_duration;

    std::cout << "-- Songs in playlist: --" << std::endl;
    for (const auto& song : playlist)
    {
        if (total_duration + song.duration <= run_duration)
        {
            std::cout << song.title << " by " << song.artist << " (" << song.duration << ")" << std::endl;
            total_duration += song.duration;
        }
    }
    std::cout << "-- Total duration: " << total_duration << " min --" << std::endl;

    return 0;
}