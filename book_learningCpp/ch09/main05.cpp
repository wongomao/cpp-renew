# include <iostream>

// X-macro

// !! will not compile

#define COLOR_LIST \
X(Red) \
X(Yellow) \
X(Blue) \
X(Green) \
X(White) \
X(Black) \
X(Purple) \
X(Orange) \
X(Pink) \
X(Brown) \
X(Gray) \
X(Light_Green) \
X(Light_Blue)

#define X(color) color,
enum Color { COLOR_LIST NUMBER_OF_COLORS };
#undef X

// This is a function that returns a string representation of the color
int main()
{
    Color color = Red;
    std::cout << "color = " << color << std::endl;
    return 0;
}