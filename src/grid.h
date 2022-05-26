#ifndef GRID_H
#define GRID_H
#include <vector> 

struct Index
{
    size_t rows;
    size_t columns;
    Index() = default;
    Index(size_t row, size_t col) : rows(row), columns(col){}

    bool cell_is_in_range(const Index& max)
    {
        return rows >= 0 && rows < max.rows && columns>=0 && columns < max.columns;
    }
    bool cell_is_in_range(const Index& min, const Index& max)
    {
        return rows >= min.rows && rows < max.rows && columns >= min.columns && columns < max.columns;
    }
};

std::vector<size_t> range(size_t end)
{
    std::vector<size_t> res(end);
    for (auto i = 0u; i < end; i++)
    {
        res.at(i)= i;
        return res;
    }
}

template <class T>
class Grid
{
    std::vector<T> data;
    size_t rows;
    size_t columns;

    public:
    // default construct
    Grid() = default;
    // constructor that creates n x m grid
    Grid(size_t row, size_t col) : data(col * row), rows(row), columns(col){}
    Grid(size_t row, size_t col, T initial_entry) : Grid(row, col)
    {
        for (auto& init_ent : data)
        {
            init_ent = initial_entry;
        }
    }
    // creates grid with random entries in each element
    Grid(size_t row, size_t col, T(initialiser)(void )) : Grid(row, col)
    {
        for (auto& init_ent : data)
        {
            init_ent = initialiser();
        }
    }

    T& at(size_t row, size_t col) { return data.at(row * columns + col);}
    T atConst(size_t row, size_t col) const{ return data.at(row * columns + col);}

    std::vector<Index> get_neighbours(size_t row, size_t col) const
    {
        std::vector<Index> neighbours;
        for (auto i = -1; i <=1; ++i)
        {
            for (auto j = -1; j <=1; ++j)
            {
                if (i == 0 && j == 0){ continue;}

                Index index(row + i, col + j);
                if(index.cell_is_in_range(max_index()))
                {
                    neighbours.push_back(index);
                }
            }
        }
        return neighbours;
    }

    size_t row_size() const { return rows;}
    size_t col_size() const { return columns;}
    size_t data_size() const { return data.size();}

    Index max_index() const { return Index(rows, columns);}

};

#endif