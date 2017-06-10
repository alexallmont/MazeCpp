#include "maze/graph/grid.hpp"

namespace maze
{
//------------------------------------------------------------------------------
Grid::Grid(int rows, int columns) :
  m_rows(rows),
  m_columns(columns)
{
  for (int r = 0; r < m_rows; ++r)
  {
    for (int c = 0; c < m_columns; ++c)
    {
      m_cells.push_back(Cell(*this, r, c));
    }
  }
}

//------------------------------------------------------------------------------
Cell* Grid::cell_at(int row, int column)
{
  if ((row >= 0) && (column >= 0))
  {
    if ((row < m_rows) && (column < m_columns))
    {
      return &m_cells[(row * m_columns) + column];
    }
  }

  return nullptr;
}

//------------------------------------------------------------------------------
}
