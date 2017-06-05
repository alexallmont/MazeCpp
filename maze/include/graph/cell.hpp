#include <functional>
#include <vector>

namespace maze
{
  // A cell in a 2D grid, contains set of links and can be referred
  // to by compass points.
  //
  class Cell
  {
    Cell(const Grid& _grid, int _row, int _column) :
      grid(_grid),
      row(_row),
      column(_column) {}

    Cell* north() const { return nullptr; }
    Cell* east() const { return nullptr; }
    Cell* south() const { return nullptr; }
    Cell* west() const { return nullptr; }

  private:
    cont Grid& grid;
    int row;
    int column;
    std::vector<std::reference_wrapper<Cell>> links;
  };
}
