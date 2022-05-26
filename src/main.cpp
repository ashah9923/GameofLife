#include <iostream>
#include <thread>
#include <chrono>
#include "grid.h"

const char live_cell = 'O';
const char dead_cell = '-';


void show_grid(const Grid<char>& grid)
{
    for (size_t row = 0; row < grid.row_size(); row++)
    {
        for (size_t col = 0; col < grid.col_size(); col++)
        {
            std::cout << (grid.atConst(row, col) ? live_cell : dead_cell);
        }
        std::cout << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    Grid<char> grid(20,40, [](void){return (char)(rand()% 10 == 0);});
    
    show_grid(grid);
    
    
    return 0;
}