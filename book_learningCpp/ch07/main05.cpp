#include <iostream>
#include <sstream>
#include <vector>

int main()
{
    // std::string input = "10 20 30 40 50";
    // std::stringstream stream(input);

    // int n;
    // while (stream >> n)
    // {
    //     std::cout << n << std::endl;
    // }
    /*output:
    10
    20
    30
    40
    50
    */

   std::string line{ "I am writing several sentences. This is the 2nd one. And this is the 3rd one. This is number 4" };
   std::vector<std::string> sentences;
   std::istringstream iss(line);
   std::string sentence;
   std::string white_space{ " \t\n\r\f\v" };
   while (std::getline(iss, sentence, '.')) // split by '.' - return each as 'sentence'
   {
        if (!sentence.empty())
        {
            size_t first = sentence.find_first_not_of(white_space);
            size_t last = sentence.find_last_not_of(white_space);
            sentence = sentence.substr(first, (last - first + 1));
            sentence += ".";
            sentences.push_back(sentence);
        }
   }

   for (size_t i = 0; i < sentences.size(); i++)
   {
        std::cout << "Sentence #" << i << " is: " << sentences[i] << std::endl;
   }

/*
output:
Sentence #0 is: I am writing several sentences.
Sentence #1 is: This is the 2nd one.
Sentence #2 is: And this is the 3rd one.
Sentence #3 is: This is number 4.
*/
    std::cout << "Please tell me something about yourself starting with 'I am'" << std::endl;
    std::string lineIn;
    while (std::getline(std::cin, lineIn))
    {
        if (lineIn == "quit")
        {
            break;
        }
        std::string what_to_search{ "I am" };
        std::string what_to_replace{ "You are" };
        size_t f = lineIn.find(what_to_search);
        if (f != std::string::npos)
        {
            lineIn.replace(f, what_to_search.length(), what_to_replace);
        }
        std::cout << "You said: " << lineIn << std::endl;
    }

    return 0;
}