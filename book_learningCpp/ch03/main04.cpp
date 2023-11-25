#include <iostream>
#include <string>

#define currentStyle_NORMAL     0x00 // 0000 0000
#define currentStyle_BOLD       0x01 // 0000 0001
#define currentStyle_ITALIC     0x02 // 0000 0010
#define currentStyle_UNDERLINE  0x04 // 0000 0100
#define currentStyle_STRIKEOUT  0x08 // 0000 1000

#define BIT_BOLD        0x01 // 0000 0001
#define BIT_ITALIC      0x02 // 0000 0010
#define BIT_UNDERLINE   0x04 // 0000 0100
#define BIT_STRIKEOUT   0x08 // 0000 1000

// turn on a bit :  Value |= (1U << Bit);
// turn off a bit : Value &= ~(1U << Bit);
// toggle a bit :   Value ^= (1U << Bit);
// check a bit :    Value & (1U << Bit);

std::string boolToString(bool b)
{
    return b ? "true" : "false";
}

int main()
{
    unsigned int currentStyle = currentStyle_NORMAL;

    bool isBoldOn = currentStyle & ( 1U << BIT_BOLD );

    std::cout << "isBoldOn : " << boolToString(isBoldOn) << std::endl;

    return 0;
}
