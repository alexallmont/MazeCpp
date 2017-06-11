#ifndef MAZE_GRAPH_GRID2D_HPP
#define MAZE_GRAPH_GRID2D_HPP

#include <array>

namespace maze {

//------------------------------------------------------------------------------
//! A 2D maze grid of size ROWS by COLUMNS.
//------------------------------------------------------------------------------
template <int ROWS, int COLUMNS>
class Grid2d {
public:
  using GridType = Grid2d<ROWS, COLUMNS>;
  enum { INVALID_INDEX = -1 };

  //! Friendly access methods for each cell in a grid.
  class Cell {
    friend Grid2d;

  public:
    //! Get this cell's index.
    constexpr int index()  const { return m_index; }

    //! Return true if cell has valid index, false if invalid.
    constexpr bool valid() const {
      return m_grid->valid_index(m_index);
    }

    //! @defgroup cell_compass Functions for getting cell's immediate neighbours.
    constexpr Cell north() const { //!< @ingroup cell_compass
      return m_grid->relative_cell(m_index, -1, 0);
    }
    constexpr Cell east() const { //!< @ingroup cell_compass
      return m_grid->relative_cell(m_index, 0, 1);
    }
    constexpr Cell south() const { //!< @ingroup cell_compass
      return m_grid->relative_cell(m_index, 1, 0);
    }
    constexpr Cell west() const { //!< @ingroup cell_compass
      return m_grid->relative_cell(m_index, 0, -1);
    }

    //! Cell equality operator.
    constexpr bool operator==(Cell cell) {
      return (cell.m_index == m_index) && (cell.m_grid == m_grid);
    }

  private:
    // Cell data is managed by the owning grid - std::array can't call constructors.
    int       m_index;  //< Each cell has index an index of (row * ROWS + column).
    GridType* m_grid;   //< Owning grid. This aliasing compiles away in release.
  };

  //! Grid constructor initialises all contained cells.
  Grid2d() {
    // Each cell's index is it's position in array. This is effectively the same
    // as iterating over rows and columns and setting as r * ROWS + c
    for (size_t i = 0; i < size(); ++i) {
      m_cells[i].m_index = i;
      m_cells[i].m_grid = this;
    }
  }

  //! Return the number of rows in this grid.
  static constexpr int rows() {
    return ROWS;
  }

  //! Return the number of columns in this grid.
  static constexpr int columns() {
    return COLUMNS;
  }

  //! Return the total number of cells.
  static constexpr size_t size() {
    return ROWS * COLUMNS;
  }

  //! Return true if the cell index lies within this grid.
  static constexpr bool valid_index(int index) {
    return (index >= 0) && (index < ROWS * COLUMNS);
  }

  //! Return index of cell at (r, c) or INVALID_INDEX if not in grid.
  static constexpr int cell_index(int r, int c) {
    // TODO bad logic: this is not catering correctly for row overflows
    int index = r * COLUMNS + c;
    return valid_index(index) ? index : INVALID_INDEX;
  }

  //! Determine the row and column of a cell from a given index.
  static constexpr bool cell_row_column(int index, int& row, int& column) {
    row = index / COLUMNS;
    column = index % COLUMNS;
    return valid_index(index);
  }

  //! Get a cell relative to a cell's position.
  //! dr is row offset and dc is column offset.
  constexpr Cell relative_cell(int cell_index, int dr, int dc) {
    int row = 0;
    int column = 0;
    if (cell_row_column(cell_index, row, column)) {
      return cell_at(row + dr, column + dc);
    }
    else {
      return invalid();
    }
  }

  //! Return an invalid cell for comparison operations.
  static constexpr Cell invalid() {
    Cell cell;
    cell.m_index = INVALID_INDEX;
    cell.m_grid = nullptr;
    return cell;
  }

  //! Get the cell at a given row and column.
  constexpr Cell cell_at(int r, int c) {
    const int index = cell_index(r, c);
    if (index == INVALID_INDEX) {
      return m_invalid;
    }
    else {
      return m_cells[index];
    }
  }

private:
  std::array<Cell, size()> m_cells;
  Cell m_invalid;
};

//------------------------------------------------------------------------------
}; // namespace maze

#endif // MAZE_GRAPH_GRID2D_HPP