#include "catch.hpp"
#include "maze/graph/grid.hpp"

TEST_CASE("a lone cell has no neighbours", "[cell]")
{
  maze::Grid grid(1, 1);
  maze::Cell* cell = grid.cell_at(0, 0);

  REQUIRE(cell->north() == nullptr);
  REQUIRE(cell->east() == nullptr);
  REQUIRE(cell->south() == nullptr);
  REQUIRE(cell->west() == nullptr);
}

TEST_CASE("a cell correctly accesses it's internal neighbours", "[cell]")
{
  maze::Grid grid(2, 2);
  maze::Cell* cell = grid.cell_at(0, 0);

  REQUIRE(grid.cell_at(0, 0)->east() == grid.cell_at(0, 1));
  REQUIRE(grid.cell_at(0, 0)->south() == grid.cell_at(1, 0));

  REQUIRE(grid.cell_at(0, 1)->west() == grid.cell_at(0, 0));
  REQUIRE(grid.cell_at(0, 1)->south() == grid.cell_at(1, 1));

  REQUIRE(grid.cell_at(1, 0)->east() == grid.cell_at(1, 1));
  REQUIRE(grid.cell_at(1, 0)->north() == grid.cell_at(0, 0));

  REQUIRE(grid.cell_at(1, 1)->west() == grid.cell_at(1, 0));
  REQUIRE(grid.cell_at(1, 1)->north() == grid.cell_at(0, 1));
}

TEST_CASE("a cell correctly reports external neighbours as invalid", "[cell]")
{
  maze::Grid grid(2, 2);
  maze::Cell* cell = grid.cell_at(0, 0);

  REQUIRE(grid.cell_at(0, 0)->west() == nullptr);
  REQUIRE(grid.cell_at(0, 0)->north() == nullptr);

  REQUIRE(grid.cell_at(0, 1)->east() == nullptr);
  REQUIRE(grid.cell_at(0, 1)->north() == nullptr);

  REQUIRE(grid.cell_at(1, 0)->west() == nullptr);
  REQUIRE(grid.cell_at(1, 0)->south() == nullptr);

  REQUIRE(grid.cell_at(1, 1)->east() == nullptr);
  REQUIRE(grid.cell_at(1, 1)->south() == nullptr);
}
