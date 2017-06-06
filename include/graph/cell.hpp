#ifndef GRAPH_CELL_HPP
#define GRAPH_CELL_HPP

#include <functional>
#include <vector>

namespace maze
{
  class Grid;

  // A cell in a 2D grid, contains set of links and can be referred
  // to by compass points.
  //
  class Cell
  {
  public:
    Cell(const Grid& grid, size_t row, size_t column) :
      m_grid(grid),
      m_row(row),
      m_column(column) {}

    Cell* north() const { return nullptr; }
    Cell* east() const { return nullptr; }
    Cell* south() const { return nullptr; }
    Cell* west() const { return nullptr; }

  private:
    const Grid& m_grid;
    size_t m_row;
    size_t m_column;
    std::vector<std::reference_wrapper<Cell>> links;
  };
}

#endif // GRAPH_CELL_HPP
