#ifndef DISPLAY_ROW_HPP
#define DISPLAY_ROW_HPP

#include <cstdint>
#include <iostream>

#include "terminal.hpp"

namespace asciid
{

    class DisplayRow
    {
    private:
        std::uint8_t    m_pixels;
        Color           m_colors[8];

        void    checkRange(int i);
        uint8_t mirrorAddress(uint8_t addressToMirror);

    public:
                DisplayRow();
        int     getPixelCount() const;
        void    turnPixelOn(int i);
        void    turnPixelOff(int i);
        void    flipPixel(int i);
        bool    isPixelOn(int i);
        void    clearPixels();
        Color   getPixelColor(int i);
        void    setPixelColor(int i, Color color);
        void    print();
        void    printLn();

        void    writeToDisplayRow(std::uint8_t toWrite);
        void    printLnStarsAndDots();
        void    setColorByAddress
        (
            std::uint8_t    addressToColor,
            Color           color
        );

        void    resetPixelsColor();
    };
} // namespace asciid

#endif
