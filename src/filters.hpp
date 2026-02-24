#ifndef FILTERS_HPP
#define FILTERS_HPP

#include "display.hpp"

namespace asciid
{
    namespace filters
    {
        void flip
        (
            Display* d
        );

        void repaint
        (
            Display *d, 
            Color   from, 
            Color   to
        );

        void transpose
        (
            Display *d
        );

        void fill
        (
            Display *d, 
            int row, 
            int col, 
            Color c
        );
        
    } // namspace filters  

} // namespace asciid



#endif