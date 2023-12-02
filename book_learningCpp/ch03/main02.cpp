#include <iostream>
#include <cpr/cpr.h>

int main(int argc, char** argv)
{
    auto r = cpr::Get(cpr::Url{"https://api.github.com/repos/libcpr/cpr/contributors"},
                      cpr::Authentication{"user", "pass"},
                      cpr::Parameters{{"anon", "true"}, {"key", "value"}});
    std::cout << r.status_code << std::endl;                  // 200
    std::cout << r.header["content-type"] << std::endl;       // application/json; charset=utf-8
    std::cout << r.text << std::endl;                         // JSON text string
    std::cout << r.url << std::endl;                          // https://api.github.com/repos/whoshuu/cpr/contributors?anon=true&key=value
    return 0;
}