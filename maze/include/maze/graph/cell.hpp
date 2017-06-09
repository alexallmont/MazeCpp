#ifndef MAZE_GRAPH_CELL_HPP
#define MAZE_GRAPH_CELL_HPP

#include <functional>
#include <vector>

namespace maze
{
class Grid;

//------------------------------------------------------------------------------
//! An individual cell in a 2D grid with accessors to query cells as compass
//! points.
//------------------------------------------------------------------------------
class Cell
{
public:
  Cell(Grid& grid, size_t row, size_t column);

  Cell* north() const;
  Cell* east() const;
  Cell* south() const;
  Cell* west() const;

private:
  Grid&   m_grid;
  size_t  m_row;
  size_t  m_column;
};

//------------------------------------------------------------------------------
}

#endif // MAZE_GRAPH_CELL_HPP
