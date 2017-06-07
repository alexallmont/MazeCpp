#include "maze/graph/grid.hpp"

#include <cassert>

namespace maze
{
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

  Cell& Grid::cell_at(size_t row, size_t column)
  {
    assert(row < m_rows);
    assert(column < m_columns);
    return m_cells[(row * m_columns) + column];
  }
}
