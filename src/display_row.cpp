#include "display_row.hpp"

#include <stdexcept>

namespace asciid
{
    DisplayRow::DisplayRow()
        : m_pixels(0)
    {
        for (int i = 0; i < 8; i++)
        {
            m_colors[i] = Color::White;
        }
    };

    int DisplayRow::getPixelCount() const
    {
        return 8;
    };

    void DisplayRow::turnPixelOn(int i)
    {
        if (!isPixelOn(i))
        {
            flipPixel(i);
        }
    };

    void DisplayRow::checkRange(int i)
    {
        if (i < 0 || i > 7)
        {
            throw std::out_of_range("Invalid index!");
        }
    };

    void DisplayRow::turnPixelOff(int i)
    {
        if (DisplayRow::isPixelOn(i))
        {
            DisplayRow::flipPixel(i);
        }
        else
        {
            return;
        }
    };

    void DisplayRow::flipPixel(int i)
    {
        DisplayRow::checkRange(i);
        m_pixels = m_pixels ^ (1 << i);
    };

    bool DisplayRow::isPixelOn(int i)
    {
        DisplayRow::checkRange(i);
        uint8_t temp_bitmap = (1 << i);

        if (m_pixels & temp_bitmap)
        {
            return true;
        }
        return false;
    };

    void DisplayRow::clearPixels()
    {
        m_pixels = 0;
    };

    Color DisplayRow::getPixelColor(int i)
    {
        DisplayRow::checkRange(i);
        return m_colors[i];
    }

    void DisplayRow::setPixelColor(int i, Color color)
    {
        DisplayRow::checkRange(i);
        m_colors[i] = color;
    }

    void DisplayRow::print()
    {
        for (int i = 0; i < 8; i++)
        {
            if ((m_pixels >> i) & 1)
            {
                Terminal::setTextColor(m_colors[i]);
                std::cout << "1";
            }
            else
            {
                Terminal::resetTextColor();
                std::cout << "0";
            }
        }

        Terminal::resetTextColor();
    }

    void DisplayRow::printLn()
    {
        DisplayRow::print();
        std::cout << "\n";
    }

    void DisplayRow::writeToDisplayRow(std::uint8_t toWrite)
    {
        m_pixels = toWrite;
    }

    void DisplayRow::printLnStarsAndDots()
    {
        for (int i = 0; i < 8; i++)
        {
            if ((m_pixels >> i) & 1)
            {
                Terminal::setTextColor(m_colors[i]);
                std::cout << "*";
            }
            else
            {
                Terminal::resetTextColor();
                std::cout << ".";
            }
        }

        std::cout << "\n";
        Terminal::resetTextColor();
    }

    void DisplayRow::setColorByAddress(
        std::uint8_t    addressToColor,
        Color           color)
        {
        const int pixelCount = getPixelCount();
        for (int i = 0; i < pixelCount; ++i)
        {
            if (addressToColor & 0x01)
            {
                m_colors[i] = color;
            }

            addressToColor >>= 1;
        }
    }

    void DisplayRow::resetPixelsColor()
    {
        for (int i = 0; i < 8; i++)
        {
            m_colors[i] = asciid::Color::White;
        }
    }

} // namespace asciid
