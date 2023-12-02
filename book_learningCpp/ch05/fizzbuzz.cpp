#include <iostream>


// the goal is to print fizz for numbers divisible by 5 or numbers that contain 5
// and buzz for numbers divisible by 7 or numbers that contain 7
int main() {
    unsigned int i{1};
    const unsigned int MAX_BEFORE_ASK{24};
    unsigned int count{0};
    const unsigned int DIVISOR_1{5}; // fizz
    const unsigned int DIVISOR_2{7}; // buzz

    // this is not fully accurate since it will print 7's on higher numbers like 178
    while (count < MAX_BEFORE_ASK) {
        bool fizzed{false};
        bool buzzed{false};
        if (i % DIVISOR_1 == 0 || i % 10 == DIVISOR_1 || i / 10 == DIVISOR_1) {
            std::cout << "Fizz";
            fizzed = true;
        }
        if (i % DIVISOR_2 == 0 || i % 10 == DIVISOR_2 || i / 10 == DIVISOR_2) {
            std::cout << "Buzz";
            buzzed = true;
        }
        if (!fizzed && !buzzed) {
            std::cout << i;
        }
        std::cout << std::endl;
        i++;
        count++;

        if (count == MAX_BEFORE_ASK) {
            std::cout << "Do you want to continue? (y/n) ";
            char answer{};
            std::cin >> answer;
            if (answer == 'y') {
                count = 0;
            } else {
                break;
            }
        }
    }
}