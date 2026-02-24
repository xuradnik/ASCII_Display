#include "display.hpp"
#include "heap_monitor.hpp"

namespace asciid
{
    Display::Display()
    {

        for (unsigned int i = 0; i < N_ROWS; i++)
        {
            m_rows[i] = new DisplayRow();
        }
    }

    Display::~Display()
    {
        for (unsigned int i = 0; i < N_ROWS; i++)
        {
            delete m_rows[i];
        }
    }

    int Display::getRowCount()
    {
        return N_ROWS;
    }

    int Display::getColCount()
    {
        return m_rows[0]->getPixelCount();
    }

    void Display::turnPixelOn(int row, int col)
    {
        if (checkRange(row))
        {
            m_rows[row]->turnPixelOn(col);
        }
    }

    void Display::turnPixelOff(int row, int col)
    {
        if (checkRange(row))
        {
            m_rows[row]->turnPixelOff(col);
        }
    }

    void Display::flipPixel(int row, int col)
    {
        if (checkRange(row))
        {
            m_rows[row]->flipPixel(col);
        }
    }

    bool Display::isPixelOn(int row, int col)
    {
        if (checkRange(row))
        {
            return m_rows[row]->isPixelOn(col);
        }
        return false;
    }

    void Display::clearPixels()
    {
        for (unsigned int i = 0; i < N_ROWS; i++)
        {
            m_rows[i]->clearPixels();
        }
    }

    Color Display::getPixelColor(int row, int col)
    {
        if (checkRange(row))
        {
            return m_rows[row]->getPixelColor(col);
        }
        return Color::White;
    }

    void Display::setPixelColor(int row, int col, Color color)
    {
        if (checkRange(row))
        {
            m_rows[row]->setPixelColor(col, color);
        }
    }

    void Display::print()
    {
        for (unsigned int i = 0; i < N_ROWS; i++)
        {
            m_rows[i]->printLn();
        }
    }

    void Display::printRow(int row)
    {
        if (checkRange(row))
        {
            m_rows[row]->printLn();
        }
    }

    void Display::writeToDisplay(
        std::uint64_t inputAdress,
        std::uint64_t addressToColor,
        Color color
    ){
        resetDisplay();

        if (N_ROWS == 8 && (m_rows[0]->getPixelCount() == 8))
        {
            std::uint8_t dissectedAddress[8];
            std::uint8_t dissectedAddressToColor[8];

            const int rowCount = getRowCount();

            for (int i = 0; i < rowCount; i++)
            {
                // Convertujem LSB z 64bit na 8bit
                dissectedAddress[i] = inputAdress;
                dissectedAddressToColor[i] = addressToColor;

                // Posuniem adresu o 8 bitov pre dalsiu itteraciu
                inputAdress = inputAdress >> 8;
                addressToColor = addressToColor >> 8;

                // adresa pre vyfarbenie je otocena preto iterujem z drujeh strany
                m_rows[i]->writeToDisplayRow(dissectedAddress[i]);
                m_rows[i]->setColorByAddress(dissectedAddressToColor[i], color);
            }
        }

        return;
    }

    void Display::printSpecialSyntax()
    {
        for (int i = 0; i < getRowCount(); i++)
        {
            m_rows[i]->printLnStarsAndDots();
        }
    }

    bool Display::checkRange(int row) const
    {
        return (row >= 0 && row < static_cast<int>(N_ROWS));
    }

    void Display::resetDisplay()
    {
        clearPixels();

        for (unsigned int i = 0; i < N_ROWS; i++)
        {
            m_rows[i]->resetPixelsColor();
        }
    }

} // namespace asciid
