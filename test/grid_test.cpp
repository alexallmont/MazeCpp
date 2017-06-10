#include "catch.hpp"
#include "maze/graph/grid.hpp"

TEST_CASE("a grid correctly reports its row and column sizes", "[grid]")
{
  maze::Grid grid(3, 4);
  REQUIRE(grid.rows() == 3);
  REQUIRE(grid.columns() == 4);
}

TEST_CASE("an empty grid is valid but its cells are not", "[grid]")
{
  maze::Grid grid(0, 0);
  SECTION("querying a cell yields an invalid result")
  {
    REQUIRE(grid.cell_at(0, 0) == nullptr);
  }

  SECTION("the rows and columns are zero")
  {
    REQUIRE(grid.rows() == 0);
    REQUIRE(grid.columns() == 0);
  }
}

TEST_CASE("a non-empty grid containts cells", "[grid]")
{
  constexpr int rows = 3;
  constexpr int columns = 2;

  maze::Grid grid(rows, columns);
  for (int r = 0; r < rows; ++r)
  {
    for (int c = 0; c < columns; ++c)
    {
      REQUIRE(grid.cell_at(r, c) != nullptr);
    }
  }
}
