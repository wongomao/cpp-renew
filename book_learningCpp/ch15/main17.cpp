#include <iostream>
#include <chrono>
#include <thread>
#include <coroutine>

class TimerAwaitable
{
public:
    TimerAwaitable(std::chrono::milliseconds duration) : duration(duration) {}
 
    bool await_ready() const 
    {
        return false;
    }
 
    void await_suspend(std::coroutine_handle<> handle)
    {
        std::thread([this, handle]()
            {
            std::this_thread::sleep_for(duration);
            handle.resume();
            }).detach();
    }
 
    void await_resume() {}
 
private:
    std::chrono::milliseconds duration;
};

struct Task
{
    struct promise_type
    {
        Task get_return_object() 
        {
            return {};
        }
        std::suspend_never initial_suspend()
        {
            return {};
        }
        std::suspend_never final_suspend() noexcept
        {
            return {};
        }
        void return_void() {}
        void unhandled_exception() {}
    };
};

Task simpleCoroutine()
{
    std::cout << "Coroutine started." << std::endl;
    co_await TimerAwaitable{ std::chrono::seconds(2) };
    std::cout << "Coroutine resumed after waiting." << std::endl;
}

int main() 
{
    std::cout << "Starting coroutine..." << std::endl;
    simpleCoroutine();
    std::cout << "Coroutine finished." << std::endl;
 
    return 0;
}