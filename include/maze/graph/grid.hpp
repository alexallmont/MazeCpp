#ifndef GRAPH_GRID_HPP
#define GRAPH_GRID_HPP

#include <vector>
#include "maze/graph/cell.hpp"

namespace maze
{
  // A 2D grid containing cells that maintain links in a maze
  //
  class Grid
  {
  public:
    Grid(size_t rows, size_t columns);
    Grid(const Grid&) = delete;
    Grid& operator=(const Grid&) = delete;

    Cell& cell_at(size_t row, size_t column);

    size_t rows() const { return m_rows; }
    size_t columns() const { return m_columns; }

  private:
    size_t m_rows;
    size_t m_columns;
    std::vector<Cell> m_cells;
  };
}

#endif // GRAPH_GRID_HPP
