#include "game_of_life.hpp"
#include "heap_monitor.hpp"

namespace gol
{
    GameOfLife::GameOfLife()
        : m_activeDisplay(new asciid::Display()),
          m_bufferDisplay(new asciid::Display())
    {
        if (m_activeDisplay->getRowCount() == m_bufferDisplay->getRowCount())
        {
            m_BothDisplayRows = m_activeDisplay->getRowCount();
        }
        else
        {
            m_BothDisplayRows = -1;
        }

        if (m_activeDisplay->getColCount() == m_bufferDisplay->getColCount())
        {
            m_BothDisplayColms = m_activeDisplay->getColCount();
        }
        else
        {
            m_BothDisplayColms = -1;
        }
    }

    GameOfLife::~GameOfLife()
    {
        delete m_activeDisplay;
        delete m_bufferDisplay;
    }

    bool GameOfLife::cellExists(int row, int col)
    {
        if (((row >= 0) && (row < m_BothDisplayRows)) && ((col >= 0) && (col < m_BothDisplayColms)))
        {
            return true;
        }
        return false;
    }

    void GameOfLife::setCellAlive(int row, int col)
    {
        if (cellExists(row, col))
        {
            m_bufferDisplay->turnPixelOn(row, col);
            m_activeDisplay->turnPixelOn(row, col);
        }
        return;
    }

    void GameOfLife::tick()
    {
        for (int i = 0; i < m_BothDisplayRows; i++)
        {
            for (int j = 0; j < m_BothDisplayColms; j++)
            {
                int t_aliveNeighbour = getActiveCellsCount(i, j);
                bool alive = m_activeDisplay->isPixelOn(i, j);

                if (alive)
                {

                    if (t_aliveNeighbour < 2 || t_aliveNeighbour > 3)
                    {
                        m_bufferDisplay->turnPixelOff(i, j);
                    }
                    else
                    {
                        m_bufferDisplay->turnPixelOn(i, j);
                    }
                }
                else
                {

                    if (t_aliveNeighbour == 3)
                    {
                        m_bufferDisplay->turnPixelOn(i, j);
                    }
                    else
                    {
                        m_bufferDisplay->turnPixelOff(i, j);
                    }
                }
            }
        }
    }
    bool GameOfLife::isCellAlive(int row, int col)
    {
        if (m_bufferDisplay->isPixelOn(row, col))
        {
            return true;
        }
        return false;
    }

    void GameOfLife::run(int tickCount)
    {
        if (tickCount > 0)
        {
            for (int i = 0; i < tickCount; i++)
            {
                tick();
                printState();
                flipDisplays();
            }
        }
    }

    void GameOfLife::printState() const
    {
        m_activeDisplay->print();
        std::cout << "\n\n"
                  << std::endl;
    }

    int GameOfLife::getActiveCellsCount(int row, int col)
    {
        int activeCells = 0;

        for (int i = row - 1; i <= row + 1; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                if (cellExists(i, j) && m_activeDisplay->isPixelOn(i, j))
                {

                    if (!(i == row && j == col))
                    {
                        activeCells++;
                    }
                }
            }
        }

        return activeCells;
    }

    void GameOfLife::flipDisplays()
    {

        for (int i = 0; i < m_BothDisplayRows; ++i)
        {
            for (int j = 0; j < m_BothDisplayColms; ++j)
            {
                if (m_bufferDisplay->isPixelOn(i, j))
                {
                    m_activeDisplay->turnPixelOn(i, j);
                }
                else
                {
                    m_activeDisplay->turnPixelOff(i, j);
                }
            }
        }
    }

    GameOfLife *GameOfLife::createToad()
    {
        GameOfLife *game = new gol::GameOfLife();
        game->setCellAlive(3, 3);
        game->setCellAlive(3, 4);
        game->setCellAlive(3, 5);
        game->setCellAlive(4, 2);
        game->setCellAlive(4, 3);
        game->setCellAlive(4, 4);

        return game;
    }

    GameOfLife *GameOfLife::createDiehard()
    {
        GameOfLife *game = new gol::GameOfLife();
        game->setCellAlive(0, 6);
        game->setCellAlive(1, 0);
        game->setCellAlive(1, 1);
        game->setCellAlive(2, 1);
        game->setCellAlive(2, 5);
        game->setCellAlive(2, 6);
        game->setCellAlive(2, 7);

        return game;
    }

    GameOfLife *GameOfLife::createEmpty()
    {
        GameOfLife *game = new gol::GameOfLife();
        return game;
    }

    GameOfLife *GameOfLife::CreateByUser()
    {
        return nullptr;
    }

} // namespace gol
