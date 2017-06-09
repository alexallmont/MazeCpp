#include "maze/graph/grid.hpp"

#include <cassert>

#include "maze/graph/cell.hpp"

namespace maze
{
//------------------------------------------------------------------------------
Grid::Grid(size_t rows, size_t columns) :
  m_rows(rows),
  m_columns(columns)
{
  for (size_t r = 0; r < m_rows; ++r)
  {
    for (size_t c = 0; c < m_columns; ++c)
    {
      m_cells.emplace_back(*this, r, c);
    }
  }
}

//------------------------------------------------------------------------------
Cell* Grid::cell_at(int row, int column)
{
  if ((row >= 0) and (column >= 0))
  {
    size_t r = (size_t)row;
    size_t c = (size_t)column;
    if ((r < m_rows) and (c < m_columns))
    {
      return &m_cells[(r * m_columns) + c];
    }
  }

  return nullptr;
}

//------------------------------------------------------------------------------
}