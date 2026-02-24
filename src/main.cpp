#include "display_row.hpp"
#include "display.hpp"
#include "terminal.hpp"
#include "filters.hpp"
#include "game_of_life.hpp"
#include "ui_utils.hpp"
#include "set_visualizer.hpp"

#include <iostream>
#include <string>



int main()
{
    
        std::uint64_t vstup_a = 0x0F0F0F0F0F0F0F0F;
        std::uint64_t vstup_b = 0xFFFFFFFF00000000;

        setvis::SetVisualizer *visualizer = new setvis::SetVisualizer();

        std::cout << "Intersection" << std::endl;
        visualizer->showIntersection(vstup_a, vstup_b);
        std::cout << "\n";

        std::cout << "Union" << std::endl;
        visualizer->showUnion(vstup_a, vstup_b);
        std::cout << "\n";

        std::cout << "Difference" << std::endl;
        visualizer->showDifference(vstup_a, vstup_b);
        std::cout << "\n";

        std::cout << "Complement" << std::endl;
        visualizer->showComplement(vstup_a);
        std::cout << "\n";

        delete visualizer;
}




