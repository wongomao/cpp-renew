#include <iostream> 
#include <random> 
#include <coroutine> 
#include <concepts> 

template <std::integral T> // T must be an integral type
struct generator
{
    struct promise_type; // forward declaration
    // define a type alias for the coroutine handle with the promise_type
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type 
    { 
        T value; // current value of the generator

        generator get_return_object()
        {
            // return a generator instance when the coroutine starts
            return generator{ handle_type::from_promise(*this) };
        }

        // suspend the coroutine initially and return to the caller
        std::suspend_always initial_suspend()
        {
            return {};
        }

        // suspend the coroutine when it is about to finish
        std::suspend_always final_suspend() noexcept
        {
            return {};
        }

        // suspend the coroutine while yielding a value
        std::suspend_always yield_value(T value_)
        {
            value = value_;
            return {};
        }

        // return nothing from the generator when the coroutine finishes
        void return_void()
        {
        }

        // handle any unhandled exceptions in the coroutine
        void unhandled_exception()
        {
        }
    };

    // constructor for the generator struct taking a coroutine handle
    explicit generator(handle_type handle) : handle_(handle)
    {
    }

    // destructor for the generator struct, destroys the coroutine handle
    ~generator()
    {
        if (handle_)
            handle_.destroy();
    }

    // delete the copy constructor to make the generator move-only
    generator(const generator&) = delete;
    // delete the copy assignment operator to make the generator move-only
    generator& operator=(const generator&) = delete;
    // move constructor for the generator struct
    generator(generator&& other) noexcept : handle_(other.handle_)
    {
        other.handle_ = {}; 
    }

    // move assignment operator for the generator struct
    generator& operator=(generator&& t) noexcept
    {
        // check if the object is being assigned to itself
        if (this == &t)
            return *this; 
        // destroy the current coroutine handle if it is valid
        if (handle_)
            handle_.destroy(); 
        // move the coroutine handle from the other object
        handle_ = t.handle_;
        // set the other object's handle to an empty state
        t.handle_ = {};
        // return a reference to the current object
        return *this;
    }

    // resume the coroutine and return the value yielded
    int operator()()
    {
        handle_.resume(); 
        return (handle_.promise().value); 
    }

    // check if the coroutine is done executing
    [[nodiscard]] bool done() const noexcept
    {
        return (handle_.done());
    }

    private:
    handle_type handle_; // store the coroutine handle
};

// define a generator function that yields random numbers
generator<int> random_numbers(int count, int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);

    for (int i = 0; i < count; ++i)
    {
        // create a generator instance with the random_numbers function
        co_yield dist(gen);
    }
}

int main()
{
    int count = 10;
    int min = 1;
    int max = 100;
    generator<int> random_nums = random_numbers(count, min, max);

    while (!random_nums.done())
    {
        std::cout << random_nums() << " ";
    }

    return 0;
} 