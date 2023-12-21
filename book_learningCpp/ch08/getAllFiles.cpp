#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;

/*
Our recursive function is using directory_iterator which iterates over the directory_entry
elements of a directory (but does not visit the subdirectories). When we hit 
a subdirectory, our function recursively calls itself, and by doing so, we get the
entire list of files in all folders and subfolders.
*/
void RecGetAllFiles(wstring path,
    vector<wstring>& filenames,
    const wstring& space)
{
    // We use a filsystem::path variable named 'filesVault' to hold the current folder
    const filesystem::path filesVault{ path };
    try
    {
        // We iterate over the files and folders within a given path
        for (auto const& dirEntry : filesystem::directory_iterator{ filesVault })
        {
            wcout << space << dirEntry.path().filename().wstring() << L'\n';

            // If the path we have found is a file, we add it to our 'filenames' vector
            filenames.push_back(dirEntry.path().wstring());
            // If the path we have found is a directory, we recursively call ourselves
            // passing this directory as the first parameter
            if (dirEntry.is_directory())
            {
                // recursive call
                RecGetAllFiles(dirEntry.path().wstring(), filenames, L"    " + space);
            }
        }
    }

    /*
    Here we handle all kinds of errors using the std::filesystem::filesystem_error class.
    This class defines an exception object that is thrown on failure by the
    throwing overlords of the functions in the filesystem library.
    */
    catch(filesystem::filesystem_error const& ex)
    {
        wcout << L"Error: " << endl
            << L"what():  " << ex.what() << endl
            << L"path1(): " << ex.path1().wstring() << endl
            << L"path2(): " << ex.path2().wstring() << endl;
    }
}

/*
scanFilesAndPrintResult() is the function that will be called from main
1. initial path
2. vector of filenames

We call our recursive function RecGetAllFiles with the initial path, the vector, and
    indicating how we represent the various levels of the directory
    structure. In our case, we use the string " |_>" to indicate the level.
*/
void scanFilesAndPrintResult(wstring path, vector<wstring>& filenames)
{
    wcout << path << endl;
    RecGetAllFiles(path, filenames, L" |_>");
}

/*
Our main program: The user can indicate the starting path from which files
and folders are scanned. The user can either pass this path as a parameter
or enter it during runtime.

Note that the compiler complains about the main function signature. This is
because the main function is defined as taking a char** as the second parameter
and not a wchar_t**. This is because the main function is defined in the C
standard library, which does not support wide characters.

Running this, passing the path as a parameter does not work. Instead, just
run the program and enter the path during runtime.
*/
int main(int argc, wchar_t** argv)
{
    wstring path;
    if (argc == 1)
    {
        wcout << L"Please enter a starting path to scan all files within it: " << endl;
        // we use getline() for input as the path might be long with spaces
        getline(wcin, path);
    }
    else if (argc == 2)
    {
        path = argv[1];
    }
    // we define our main vector of wstring, and call it filenames
    vector <wstring> filenames = vector<wstring>();
    scanFilesAndPrintResult(path, filenames);

    // we define our iterator as 'auto' and it is used to go over the results.
    // We then go over all the results and print them.
    for (auto it = filenames.begin(); it != filenames.end(); ++it)
    {
        wstring s((*it).begin(), (*it).end());
        wcout << s << endl;
    }

    return 0;
}