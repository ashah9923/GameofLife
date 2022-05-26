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

void update_grid(Grid<char>& grid)
{
    Grid<char>duplicate_grid(grid);
    for (size_t row = 0; row < grid.row_size(); row++)
    {
        for (size_t col = 0; col < grid.col_size(); col++)
        {
            int num_of_alive_neighbours = 0;
            auto index_of_neighbours = duplicate_grid.get_neighbours(row, col);
            for (auto index : index_of_neighbours)
            {
                num_of_alive_neighbours += duplicate_grid.at(index.rows, index.columns);
            }

            if (duplicate_grid.at(row, col))
            {
                if (num_of_alive_neighbours < 2 || num_of_alive_neighbours > 3)
                {
                    grid.at(row,col) = 0;
                }
                else
                {
                    if (num_of_alive_neighbours == 3)
                    {
                        grid.at(row, col) = 1;
                    }
                }
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    Grid<char> grid(20,40, [](void){return (char)(rand()% 10 == 0);});
    
    for (auto turn : range(100))
    {
        show_grid(grid);
        
        update_grid(grid);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("cls");
    }
    
    
    return 0;
}