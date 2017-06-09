#ifndef GRAPH_CELL_HPP
#define GRAPH_CELL_HPP

#include <functional>
#include <vector>

#include "maze/graph/grid.hpp"

namespace maze
{
//------------------------------------------------------------------------------
//! An individual cell in a 2D grid with accessors to query cells as compass
//! points.
//------------------------------------------------------------------------------
class Cell
{
public:
  Cell(Grid& grid, size_t row, size_t column) :
    m_grid(grid),
    m_row(row),
    m_column(column) {}

  Cell* north() const { return m_grid.cell_at(m_row - 1, m_column); }
  Cell* east()  const { return m_grid.cell_at(m_row, m_column + 1); }
  Cell* south() const { return m_grid.cell_at(m_row + 1, m_column); }
  Cell* west()  const { return m_grid.cell_at(m_row, m_column - 1); }

private:
  Grid&   m_grid;
  size_t  m_row;
  size_t  m_column;
};

//------------------------------------------------------------------------------
}

#endif // GRAPH_CELL_HPP
