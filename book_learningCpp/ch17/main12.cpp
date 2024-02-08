/* Using Regex to generate an output file with annotated comments */
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <vector>

std::string generateProgressingAnnotations(int count)
{
    std::string annotation = "// #";
    char ch = 'A' + count;
    annotation += ch;
    return annotation;
}

int main()
{
    std::string inputFileName;
    std::cout << "Enter the input file name: ";
    std::cin >> inputFileName;

    std::ifstream inputFile(inputFileName);
    if (!inputFile)
    {
        std::cerr << "Error opening input file " << inputFileName << std::endl;
        return 1;
    }

    std::vector<std::string> lines;
    std::vector<std::string> originalTexts;
    std::string line;
    int count = 0;

    while (std::getline(inputFile, line))
    {
        // match comments starting with "//"
        // \s is whitespace character; \S is non-whitespace character
        // * zero or more of the preceding character
        // () is a capturing group
        // . is any character except newline
        // (\S.*) is a capturing group that matches a non-whitespace character followed by zero or more of any character
        std::regex commentRegex(R"(\/\/\s*(\S.*))");
        std::smatch commentMatch;
        if (std::regex_search(line, commentMatch, commentRegex))
        {
            // extract the original text from the captured group in the comment match
            // and store it in the originalTexts vector
            std::string originalText = commentMatch[1].str();
            originalTexts.push_back(originalText);
            // generate a progressing annotation using 'generateProgressingAnnotations' function
            std::string annotation = generateProgressingAnnotations(count);
            count++;
            // replace the comment in the current line with the generated annotation
            line = std::regex_replace(line, commentRegex, annotation);
        }
        lines.push_back(line);
    }

    inputFile.close(); // close the input file after reading all lines

    std::string outputFileName = "output.cpp";
    std::ofstream outputFile(outputFileName); // open for writing
    if (!outputFile)
    {
        std::cerr << "Error opening output file " << outputFileName << std::endl;
        return 1;
    }
    // iterate throug the lines vector and write each line to the output file
    for (const std::string& line : lines)
    {
        outputFile << line << std::endl;
    }
    // iterate through the 'originalTexts' vector and
    // write annotations with their corresponding original texts to the output file
    for (int i = 0; i < count; ++i)
    {
        outputFile << "// #" << (char)('A' + i) << " " << originalTexts[i] << std::endl;
    }
    outputFile.close(); // close the output file after writing all lines

    return 0;
}