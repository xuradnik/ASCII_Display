#ifndef TERMINAL
#define TERMINAL

#include <iostream>

namespace asciid
{

enum class Color
{
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37
};


class Terminal
{
    private:

    public:
    static void clear();
    static void setTextColor(Color c);
    static void resetTextColor();

};

} // namespace asciid


#endif
