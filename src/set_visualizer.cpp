#include "set_visualizer.hpp"

namespace setvis
{

    SetVisualizer::SetVisualizer()
        : m_Display(new asciid::Display())
    {
        p_m_AddressToColor = new uint64_t;
    }

    SetVisualizer::~SetVisualizer()
    {
        delete m_Display;
        delete p_m_AddressToColor;
    }

    std::uint64_t SetVisualizer::calcIntersection(
        std::uint64_t a,
        std::uint64_t b)
    {
        *p_m_AddressToColor = a & b;
        return a | b;
    }

    std::uint64_t SetVisualizer::calcUnion(
        std::uint64_t a,
        std::uint64_t b)
    {
        *p_m_AddressToColor = a | b;
        return a | b;
    }

    std::uint64_t SetVisualizer::calcDifference(
        std::uint64_t a,
        std::uint64_t b)
    {
        std::uint64_t c = ~b;
        *p_m_AddressToColor = (a & c);

        return a | b;
    }

    std::uint64_t SetVisualizer::calcComplement(
        std::uint64_t a)
    {
        std::uint64_t b = ~a;
        *p_m_AddressToColor = b;

        return a | b;
    }

    void SetVisualizer::showIntersection(
        std::uint64_t a,
        std::uint64_t b)
    {
        std::uint64_t toPass = calcIntersection(a, b);

        m_Display->writeToDisplay(toPass, *p_m_AddressToColor, asciid::Color::Red);
        m_Display->printSpecialSyntax();
    }

    void SetVisualizer::showUnion(
        std::uint64_t a,
        std::uint64_t b)
    {
        std::uint64_t toPass = calcUnion(a, b);

        m_Display->writeToDisplay(toPass, *p_m_AddressToColor, asciid::Color::Red);
        m_Display->printSpecialSyntax();
    }

    void SetVisualizer::showDifference(
        std::uint64_t a,
        std::uint64_t b)
    {
        std::uint64_t toPass = calcDifference(a, b);

        m_Display->writeToDisplay(toPass, *p_m_AddressToColor, asciid::Color::Red);
        m_Display->printSpecialSyntax();
    }

    void SetVisualizer::showComplement(std::uint64_t a)
    {
        std::uint64_t toPass = calcComplement(a);

        m_Display->writeToDisplay(toPass, *p_m_AddressToColor, asciid::Color::Red);
        m_Display->printSpecialSyntax();
    }

}
