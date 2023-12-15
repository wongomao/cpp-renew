#include <fstream>
#include <iostream>
#include <string>
#include <format>

using namespace std;

const string MY_FILE_NAME = "Learning CPP example.txt";

int main()
{
    ofstream myfile;
    myfile.open(MY_FILE_NAME);
    if (!myfile)
    {
        cerr << "Error: Failed to open file " << MY_FILE_NAME << endl;
        return 1;
    }

    myfile << "Writing this to a file.\n";
    myfile.close();

    // ifstream input-file-stream; ate: at the end; binary: read as binary
    ifstream in(MY_FILE_NAME, ifstream::ate | ifstream::binary);
    if (!in)
    {
        cerr << "Error: Failed to open file " << MY_FILE_NAME << endl;
        return 1;
    }

    auto myFileSize = in.tellg(); // get current position of file position indicator
    string output = std::format("File \"{}\" is {} bytes", MY_FILE_NAME, (int)myFileSize); // must cast to int since 
    // cout << output.c_str() << endl; // c_str() returns a const char* (address to first character) to the string
    cout << output << endl;
  
    return 0;
}