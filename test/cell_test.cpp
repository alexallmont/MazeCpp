#include "catch.hpp"
#include "maze/graph/grid.hpp"

TEST_CASE("a lone cell has no neighbours", "[cell]")
{
  maze::Grid grid(1, 1);
  maze::Cell cell = grid.cell_at(0, 0);

  REQUIRE(cell.north() == nullptr);
  REQUIRE(cell.east() == nullptr);
  REQUIRE(cell.south() == nullptr);
  REQUIRE(cell.west() == nullptr);
}
