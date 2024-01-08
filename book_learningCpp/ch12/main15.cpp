#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <concepts>

template <typename T>
concept has_open_function = requires(T t)
{
    { t.open() } -> std::same_as<void>; // fn open() returns void
};

template <typename T>
concept has_close_function = requires(T t)
{
    { t.close() } -> std::same_as<void>; // fn close() returns void
};

// concept opening_sequence = has_open_function && has_close_function;
template <typename T>
concept opening_sequence = has_open_function<T> && has_close_function<T>;

// concept 'opening_sequence' does not appear to be used in this program

template <typename T>
class simpsons_opening 
{
public:
    simpsons_opening(const std::string& name) : name_(name) {}

    void open() 
    {
        std::cout << "INT. " << name_ << " - DAY" << std::endl;
        std::cout << "The " << name_ << " opening sequence starts." << std::endl;
        std::cout << "We see the following elements:" << std::endl;
        for (const auto& element : opening_elements) 
        {
            std::cout << "- " << element << std::endl;
        }
        std::cout << "CUT TO:" << std::endl;
    }

    void close() 
    {
        std::cout << "CUT TO BLACK." << std::endl;
        std::cout << "The " << name_ << " opening sequence ends." << std::endl;
    }

    void add_opening_element(const std::string& element) {
        opening_elements.push_back(element);
    }

    void randomize_activities()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<size_t> dist(0, activities.size() - 1);
 
        size_t random_index = dist(gen);
        opening_elements[0] += " " + activities[random_index];
 
        if (activities[random_index] == "writing on the chalkboard") 
        {
            opening_elements[0] += " - " + get_random_element(chalkboard_options);
        }
    }

private:
    std::string name_;
    std::vector<std::string> opening_elements;
    std::vector<std::string> activities = 
    {
        "writing on the chalkboard",
        "skateboarding",
        "pranking Moe's Tavern",
        "skipping school",
        "eating his homework"
    };

    std::vector<std::string> chalkboard_options = 
    {
        "\"I will not skateboard in the hallway\"",
        "\"I will not throw spitballs in class\"",
        "\"I will not prank call Moe's Tavern\"",
        "\"I will not skip school\"",
        "\"I will not eat my homework\""
    };

    template <typename U>
    U get_random_element(const std::vector<U>& vec) 
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<size_t> dist(0, vec.size() - 1);
        return vec[dist(gen)];
    }
};

int main() 
{
    std::cout << "Welcome to the Simpsons Opening Script Generator!" << std::endl;
    std::cout << "Press 'Enter' to view a Hollywood script style random Simpsons opening script, or 'q' to quit." << std::endl;

    bool quit = false;

    while (!quit) 
    {
        std::string input;
        std::getline(std::cin, input);

        if (input == "q") 
        {
            quit = true;
        }
        else 
        {
            simpsons_opening<std::string> opening("Simpsons Living Room");
            opening.add_opening_element("Bart");
            opening.add_opening_element("Lisa playing the saxophone");
            opening.add_opening_element("Maggie being scanned at the grocery store");
 
            opening.randomize_activities();
 
            opening.open();
            opening.close();
 
            std::cout << std::endl << "Press Enter to view another Simpsons opening, or 'q' to quit." << std::endl;
        }
    }

    std::cout << "Thank you for using the Simpsons Opening Viewer!" << std::endl;

    return 0;
} 