/* nested namespaces */
#include <iostream>
 
namespace MyGraphics
{
    class Renderer
    {
    public:
        void render()
        {
            std::cout << "Rendering graphics..." << std::endl;
        }
    };
 
    class Shape
    {
    public:
        void draw()
        {
            std::cout << "Drawing a shape..." << std::endl;
        }
    };
 
    namespace Utilities
    {
        void log(const std::string& message)
        {
            std::cout << "[MyGraphics] " << message << std::endl;
        }
    }
}
 
void log(const std::string& message)
{
    std::cout << "[Global] " << message << std::endl;
}
 
int main()
{
    MyGraphics::Utilities::log("Initializing graphics engine...");
 
    MyGraphics::Renderer renderer;
    MyGraphics::Shape shape;
 
    renderer.render();
    shape.draw();
 
    MyGraphics::Utilities::log("Graphics engine initialized!");
 
    // ADL will find the log() function in the global namespace
    log("Hello from ADL!");
 
    return 0;
}
/*
output:
[MyGraphics] Initializing graphics engine...
Rendering graphics...
Drawing a shape...
[MyGraphics] Graphics engine initialized!
[Global] Hello from ADL!
*/