#include <iostream>
#include <random>
#include <exception>
#include <string>
#include <thread>
#include <chrono>

class AlienSignalException : public std::exception
{
public:
    AlienSignalException(int intensity)
    {
        message = "Alien signal detected with intensity " + std::to_string(intensity);
    }
    const char* what() const noexcept override
    {
        return message.c_str();
    }
private:
    std::string message;
};

void DisplayProgressBar(int progress, int total)
{
    constexpr int barWidth = 50;

    // this '\r' does not work in Windows, it does not return the
    // cursor to the beginning of the line. What can be done to return
    // the cursor to the beginning of the line in Windows? curses library?
    std::cout << "\r[";
    const int pos = static_cast<int>(barWidth * static_cast<float>(progress) / total);
    for (int i = 0; i < barWidth; ++i)
    {
        if (i < pos)
        {
            std::cout << "=";
        }
        else if (i == pos)
        {
            std::cout << ">";
        }
        else
        {
            std::cout << " ";
        }
        std::cout << "] " << int(static_cast<float>(progress) / total * 100.0) << "%";
        std::cout.flush();
    }
}

void ScanSkyForSignals(int startIntensity, int endIntensity)
{
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(startIntensity, endIntensity);

    for (int i = startIntensity; i <= endIntensity; ++i)
    {
        DisplayProgressBar(i - startIntensity, endIntensity - startIntensity);
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // delay between scans

        const int randomNumber = distribution(generator);
        if (randomNumber == i)
        {
            throw AlienSignalException(i);
        }
    }

    DisplayProgressBar(endIntensity - startIntensity, endIntensity - startIntensity);
    std::cout << std::endl << "No alien signals detected" << std::endl;
}

void GetIntensity(int& startIntensity, int& endIntensity)
{
    while (true)
    {
        std::cout << "Please enter the starting intensity of your sky Scan (1-100): ";
        std::cin >> startIntensity;
        std::cout << "Please enter the ending intensity of your sky Scan (startIntensity-100): ";
        std::cin >> endIntensity;
        if (startIntensity > endIntensity || startIntensity < 1 || endIntensity > 100)
        {
            std::cout << "Invalid input range. Please ensure startIntensity <= endIntensity" << std::endl;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    std::cout << "Welcome to the Alien Signal Detection Program" << std::endl;
    int startIntensity, endIntensity;
    GetIntensity(startIntensity, endIntensity);

    try
    {
        ScanSkyForSignals(startIntensity, endIntensity);
    }
    catch(const AlienSignalException& e)
    {
        std::cerr << std::endl << e.what() << std::endl;
        std::cout << "Quick! Inform the authorities!" << std::endl;
    }
    catch(...)
    {
        std::cerr << std::endl << "An unknown error occurred during sky scanning" << std::endl;
    }
    
    return 0;
}