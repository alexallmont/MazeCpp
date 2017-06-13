#ifndef MAZE_GRAPH_GRID2D_HPP
#define MAZE_GRAPH_GRID2D_HPP

#include <array>
#include <random>

namespace maze {

//------------------------------------------------------------------------------
//! A 2D maze grid of size ROWS by COLUMNS.
//------------------------------------------------------------------------------
template <int ROWS, int COLUMNS>
class Grid2d {
private:
  using GridType = Grid2d<ROWS, COLUMNS>;
  enum {
    INVALID_INDEX = -1,
    SIZE = ROWS * COLUMNS
  };
  enum DirectionMask {
    NORTH = 1 << 0,
    EAST  = 1 << 1,
    SOUTH = 1 << 2,
    WEST  = 1 << 3,
  };

public:
  //! Friendly access methods for each cell in a grid.
  class Cell {
    friend Grid2d;

  public:
    //! Create an invalid cell. This is moot because all cells are created
    //! invalid by default. This just improves code readability.
    constexpr static Cell create_invalid() {
      return Cell();
    }

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

    //! Get any valid neighbours around this cell.
    std::vector<Cell> neighbours() const {
      std::vector<Cell> ns;
      if (north().valid()) ns.push_back(north());
      if (east().valid()) ns.push_back(east());
      if (south().valid()) ns.push_back(south());
      if (west().valid()) ns.push_back(west());
      return ns;
    }

    //! Cell equality operator.
    constexpr bool operator==(Cell cell) const {
      return (cell.m_index == m_index) && (cell.m_grid == m_grid);
    }

  private:
    // Cell data is managed by the owning grid - std::array can't call constructors.
    int       m_index = INVALID_INDEX;  //< Cell has index of (row * ROWS + column).
    GridType* m_grid  = nullptr;        //< Owning grid; compiles away in release build.
  };

  //! Grid constructor initialises all contained cells.
  Grid2d() {
    // Each cell's index is it's position in array. This is effectively the same
    // as iterating over rows and columns and setting as r * ROWS + c
    for (int i = 0; i < size(); ++i) {
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
  static constexpr int size() {
    return SIZE;
  }

  //! Return true if the row and column is valid.
  static constexpr bool valid_position(int row, int column) {
    return (row >= 0) && (row < ROWS) && (column >= 0) && (column < COLUMNS);
  }

  //! Return true if the cell index lies within this grid.
  static constexpr bool valid_index(int index) {
    return (index >= 0) && (index < SIZE);
  }

  //! Return index of cell at (r, c) or INVALID_INDEX if not in grid.
  static constexpr int cell_index(int row, int column) {
    return valid_position(row, column) ? ((row * COLUMNS) + column) : INVALID_INDEX;
  }

  //! Get the row for the given cell index.
  static constexpr int cell_row(int index) {
    return index / COLUMNS;
  }

  //! Get the column for the given cell index.
  static constexpr int cell_column(int index) {
    return index % COLUMNS;
  }

  //! Get a cell relative to a cell's position.
  //! dr is row offset and dc is column offset.
  constexpr Cell relative_cell(int cell_index, int dr, int dc) const {
    return cell_at(cell_row(cell_index) + dr, cell_column(cell_index) + dc);
  }

  //! Get the cell at a given row and column.
  constexpr Cell cell_at(int row, int column) const {
    return valid_position(row, column) ? m_cells[cell_index(row, column)] : Cell();
  }

  //! Get a random cell in this grid.
  Cell random_cell() const {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(0, size() - 1);
    int index = distribution(rng);
    return m_cells[index];
  }

private:
  std::array<Cell, SIZE> m_cells;     //!< 1D array of all cells in grid.
  std::array<char, SIZE> m_linkmasks; //!< Each cell's links stored as bitmask
};

//------------------------------------------------------------------------------
} // namespace maze

#endif // MAZE_GRAPH_GRID2D_HPP