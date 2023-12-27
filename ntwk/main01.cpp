#include <iostream>
#include <asio.hpp>

// https://think-async.com/Asio/
// https://www.youtube.com/watch?v=2hNdkYInj4g&list=PLIXt8mu2KcUJOwdLMp-Z-cDIZA1aZfVTN
// https://www.bing.com/search?FORM=U523DF&PC=U523&q=g%2B%2B+include+path

int main()
{
    asio::io_context io;
    asio::steady_timer t(io, asio::chrono::seconds(5));
    t.wait();
    std::cout << "Hello, world!" << std::endl;
    return 0;
}