#include "filters.hpp"

namespace asciid
{
    namespace filters
    {
        void flip
        (
            Display *d
        ){
            for(int row = 0; row < (d->getRowCount()); row++)
            {
                for(int col = 0; col < (d->getColCount()); col++)
                {
                    d->flipPixel(row, col);
                }
            }
        }

        void repaint
        (   
            Display     *d, 
            Color       from, 
            Color       to
        ){

            for(int row = 0; row < (d->getRowCount()); row++)
            {
                for(int col = 0; col < (d->getColCount()); col++)
                {
                    if(d->getPixelColor(row, col) == from)
                    {
                        d->setPixelColor(row, col, to);
                    }
                }
            }
        }


        void transpose
        (
            Display  *d
        ){

            asciid::Display* tempDisplay = new Display();

            for(int row = 0; row < (d->getRowCount()); row++)
            {
                for(int col = 0; col < (d->getColCount()); col++)
                {
                    if((d->isPixelOn(row,col)))
                    {
                        tempDisplay->turnPixelOn(col,row);
                    }

                    tempDisplay->setPixelColor(col, row, d->getPixelColor(row, col));
                }
            }

            *d = *tempDisplay;
            delete tempDisplay;
        }


        void fill
        (
            Display     *d, 
            int         row, 
            int         col, 
            Color       c
        ){
            
            bool 
                up      = false, 
                down    = false,
                right   = false,
                left    = false;

            if(row > 0)
            {
                up = true;
            }
            if(row < (d->getRowCount()) -1 )
            {
                down = true;
            }
            if(col > 0)
            {
                left = true;
            }
            if(col < (d->getColCount()) -1 )
            {
                right = true;
            }

           Color myOldColor = d->getPixelColor(row, col);

           if(myOldColor == c)
           {
            return;
           }

           d->setPixelColor(row, col, c);

           if(up)
           {
                if(d->getPixelColor(row - 1, col) == myOldColor)
                {
                    fill(d,row - 1,col,c);
                }
           }
           if(down)
           {
                if(d->getPixelColor(row + 1, col) == myOldColor)
                {
                    fill(d, row + 1 , col, c);
                }
           }
           if(right)
           {
                if(d->getPixelColor(row, col + 1) == myOldColor)
                {
                    fill(d, row, col + 1 , c);
                }
           }
           if(left)
           {
                if(d->getPixelColor(row, col - 1) == myOldColor)
                {
                    fill(d, row, col - 1 , c);
                }
           }

           return;

        }

    } // namspace filters 
} // namespace asciid
