#ifndef SET_VISUALIZER_HPP
#define SET_VISUALIZER_HPP

#include "display.hpp"
#include "terminal.hpp"

#include <cstdint>

namespace setvis
{
    struct SetVisualizer
    {

    private:
        asciid::Display *m_Display;
        uint64_t        *p_m_AddressToColor;

        const std::uint64_t A_const = 0x0F0F0F0F0F0F0F0F;
        const std::uint64_t B_const = 0xFFFFFFFF00000000;

    public:
        SetVisualizer();
        ~SetVisualizer();

        std::uint64_t calcIntersection(
            std::uint64_t a,
            std::uint64_t b);

        std::uint64_t calcUnion(
            std::uint64_t a,
            std::uint64_t b);
            
        std::uint64_t calcDifference(
            std::uint64_t a,
            std::uint64_t b);

        std::uint64_t calcComplement(
            std::uint64_t a);

        void showIntersection(
            std::uint64_t a,
            std::uint64_t b);

        void showUnion(
            std::uint64_t a,
            std::uint64_t b);

        void showDifference(
            std::uint64_t a,
            std::uint64_t b);

        void showComplement(
            std::uint64_t a);
    };

} // namespace setvis

#endif