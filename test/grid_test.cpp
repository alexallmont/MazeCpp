#include "catch.hpp"
#include "maze/graph/grid2d.hpp"

TEST_CASE("a grid correctly reports its row and column sizes", "[grid]")
{
  maze::Grid2d<3, 4> grid;
  REQUIRE(grid.rows() == 3);
  REQUIRE(grid.columns() == 4);
}

TEST_CASE("an empty grid is valid but its cells are not", "[grid]")
{
  maze::Grid2d<0, 0> grid;
  SECTION("querying a cell yields an invalid result")
  {
    REQUIRE(grid.cell_at(0, 0).valid() == false);
  }

  SECTION("the rows and columns are zero")
  {
    REQUIRE(grid.rows() == 0);
    REQUIRE(grid.columns() == 0);
  }
}

TEST_CASE("a non-empty grid containts cells", "[grid]")
{
  maze::Grid2d<2, 3> grid;
  for (int r = 0; r < grid.rows(); ++r)
  {
    for (int c = 0; c < grid.columns(); ++c)
    {
      REQUIRE(grid.cell_at(r, c).valid() == true);
    }
  }
}
