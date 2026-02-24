add_executable(asciid)
target_sources(asciid PUBLIC
display_row.cpp
display.cpp
terminal.cpp
heap_monitor.cpp
filters.cpp
game_of_life.cpp
ui_utils.cpp
set_visualizer.cpp
main.cpp

)

target_compile_options(asciid PUBLIC
-Wall
-Wextra
-Wpedantic
-std=c++20
-g
)