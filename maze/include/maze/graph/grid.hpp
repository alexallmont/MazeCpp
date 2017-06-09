#ifndef GRAPH_GRID_HPP
#define GRAPH_GRID_HPP

#include <vector>

namespace maze
{
class Cell;

//------------------------------------------------------------------------------
//! A 2D grid containing a rows x columns matrix of cells.
//------------------------------------------------------------------------------
class Grid
{
public:
  Grid(size_t rows, size_t columns);
  Grid(const Grid&) = delete;
  Grid& operator=(const Grid&) = delete;

  Cell* cell_at(int row, int column);

  size_t rows()    const { return m_rows; }
  size_t columns() const { return m_columns; }

private:
  size_t m_rows;
  size_t m_columns;

  std::vector<Cell> m_cells;
};

}

#endif // GRAPH_GRID_HPP
