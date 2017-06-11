#include "catch.hpp"
#include "maze/graph/grid2d.hpp"

TEST_CASE("a lone cell has no neighbours", "[cell]") {
  maze::Grid2d<1, 1> grid;
  auto cell = grid.cell_at(0, 0);

  REQUIRE(cell.north().valid() == false);
  REQUIRE(cell.east().valid() == false);
  REQUIRE(cell.south().valid() == false);
  REQUIRE(cell.west().valid() == false);
}

TEST_CASE("a cell correctly accesses it's internal neighbours", "[cell]") {
  maze::Grid2d<2, 2> grid;

  SECTION("north west cell has valid neighbours") {
    REQUIRE(grid.cell_at(0, 0).east() == grid.cell_at(0, 1));
    REQUIRE(grid.cell_at(0, 0).south() == grid.cell_at(1, 0));
  }

  SECTION("north east cell has valid neighbours") {
    REQUIRE(grid.cell_at(0, 1).west() == grid.cell_at(0, 0));
    REQUIRE(grid.cell_at(0, 1).south() == grid.cell_at(1, 1));
  }

  SECTION("south west cell has valid neighbours") {
    REQUIRE(grid.cell_at(1, 0).east() == grid.cell_at(1, 1));
    REQUIRE(grid.cell_at(1, 0).north() == grid.cell_at(0, 0));
  }

  SECTION("south east cell has valid neighbours") {
    REQUIRE(grid.cell_at(1, 1).west() == grid.cell_at(1, 0));
    REQUIRE(grid.cell_at(1, 1).north() == grid.cell_at(0, 1));
  }
}

TEST_CASE("a cell correctly reports external neighbours as invalid", "[cell]") {
  maze::Grid2d<2, 2> grid;

  SECTION("north west cell reports external neighbours as invalid") {
    REQUIRE(grid.cell_at(0, 0).west().valid() == false);
    REQUIRE(grid.cell_at(0, 0).north().valid() == false);
  }

  SECTION("north east cell reports external neighbours as invalid") {
    REQUIRE(grid.cell_at(0, 1).east().valid() == false);
    REQUIRE(grid.cell_at(0, 1).north().valid() == false);
  }

  SECTION("south west cell reports external neighbours as invalid") {
    REQUIRE(grid.cell_at(1, 0).west().valid() == false);
    REQUIRE(grid.cell_at(1, 0).south().valid() == false);
  }

  SECTION("south west cell reports external neighbours as invalid") {
    REQUIRE(grid.cell_at(1, 1).east().valid() == false);
    REQUIRE(grid.cell_at(1, 1).south().valid() == false);
  }
}
