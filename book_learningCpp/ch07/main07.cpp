#include <iostream> 
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#else
#include <locale>
#endif
 
int main()
{

   // _T() macro (generic-text mapping) is used to create portable code that supports both ASCII and Unicode
    // i.e. when UNICODE preprocessor directive is defined, any string marked 
    // with _T() will be treated as Unicode. Otherwise, it will be treated as ASCII.
    // L"" prefix is typically used when working with explicit wide character strings and does not depend
    // on the UNICODE preprocessor directive.

    // std::string test1{ "שלום" };
    // std::string test2{ " سلام" };
 
    // std::cout << std::string(test1) << std::endl;
    // std::cout << std::string(test2) << std::endl;


#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
#else
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());
#endif
    std::wcout << L"אבא" << std::endl;
    std::wcout << L"---------------------" << std::endl; // need to use L"" prefix for wide character strings wcout

    std::wstring test1{ L"שלום" };
    std::wstring test2{ L"سلام" };
    std::wstring test3{ L"和平" };
    // wcout means wide character output stream
    std::wcout << test1 << std::endl;
    std::wcout << test2 << std::endl;
    std::wcout << test3 << std::endl;
    // nothing prints to the console because it uses a code page. Code page = table that
    // maps characters to numbers.
    // Windows -> number 1255 is the code page for the Windows-1255 character set (includes Hebrew)
}