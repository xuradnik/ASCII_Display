#ifndef GAME_OF_LIFE_HPP
#define GAME_OF_LIFE_HPP


#include "display.hpp"

namespace gol
{
    class GameOfLife
    {
        private:
         asciid::Display *m_activeDisplay;
         asciid::Display *m_bufferDisplay;

         int m_BothDisplayRows;
         int m_BothDisplayColms;
         void flipDisplays();
         bool isCellAlive(int row, int col);
         int getActiveCellsCount(int row, int col);

         
         

        public:
            GameOfLife();
            ~GameOfLife();
            bool cellExists(int row, int col);
            void setCellAlive(int row, int col);            
            void tick();
            void run(int tickCount);
            void printState() const;            
            

            static GameOfLife* createToad();
            static GameOfLife* createDiehard();
            static GameOfLife* createEmpty();
            static GameOfLife* CreateByUser();
    };

}   // namespace GameOfLife



#endif