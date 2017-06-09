#include "catch.hpp"
#include "maze/graph/grid.hpp"

TEST_CASE("a grid reports its row and column size", "[grid]")
{
  maze::Grid grid(3, 4);

  REQUIRE(grid.rows() == 3);
  REQUIRE(grid.columns() == 4);
}
