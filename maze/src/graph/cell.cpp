#include "maze/graph/grid.hpp"

namespace maze
{
//------------------------------------------------------------------------------
Cell::Cell(Grid& grid, size_t row, size_t column) :
  m_grid(grid),
  m_row(row),
  m_column(column)
{
}

//------------------------------------------------------------------------------
Cell* Cell::north() const
{
  return m_grid.cell_at(m_row - 1, m_column);
}

//------------------------------------------------------------------------------
Cell* Cell::east() const
{
  return m_grid.cell_at(m_row, m_column + 1);
}

//------------------------------------------------------------------------------
Cell* Cell::south() const
{
  return m_grid.cell_at(m_row + 1, m_column);
}

//------------------------------------------------------------------------------
Cell* Cell::west() const
{
  return m_grid.cell_at(m_row, m_column - 1);
}

//------------------------------------------------------------------------------
}