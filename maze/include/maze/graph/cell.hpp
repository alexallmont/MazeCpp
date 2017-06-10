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
  Cell(Grid& grid, int row, int column);

  Cell* north() const;
  Cell* east() const;
  Cell* south() const;
  Cell* west() const;

private:
  Grid& m_grid;
  int   m_row;
  int   m_column;
};

//------------------------------------------------------------------------------
}

#endif // MAZE_GRAPH_CELL_HPP
