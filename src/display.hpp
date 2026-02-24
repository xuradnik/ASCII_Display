#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "display_row.hpp"

namespace asciid
{
    class Display
    {
    private:
        static const unsigned int   N_ROWS = 8;     
        DisplayRow*                 m_rows[N_ROWS];

        bool checkRange(int row) const;
        void resetDisplay();

    public:
                Display();
                ~Display();

        int     getRowCount();
        int     getColCount();

        void    turnPixelOn     (int row, int col);
        void    turnPixelOff    (int row, int col);
        void    flipPixel       (int row, int col);
        bool    isPixelOn       (int row, int col);

        void    clearPixels();

        Color   getPixelColor(
            int     row, 
            int     col
        );

        void    setPixelColor(
            int     row,
            int     col,
            Color   c
        );

        void    print();
        void    printRow(int row);

        void    writeToDisplay(
            std::uint64_t           inputAdress,
            std::uint64_t           addresToColor,
            Color                   color
        );
        
        void    printSpecialSyntax();
        
    };
} // namespace asciid


#endif 
