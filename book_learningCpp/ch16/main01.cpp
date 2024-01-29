/* namespaces */
#include <iostream>

namespace MyGraphics 
{
    class Renderer
    {
    public:
        void render()
        {
            std::cout << "Rendering..." << std::endl;
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
}

int main() 
{
    MyGraphics::Renderer renderer;
    MyGraphics::Shape shape;

    renderer.render();
    shape.draw();

    return 0;
}