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
  using Grid = maze::Grid2d<2, 2>;
  Grid grid;
  Grid::Cell nw = grid.cell_at(0, 0);
  Grid::Cell ne = grid.cell_at(0, 1);
  Grid::Cell sw = grid.cell_at(1, 0);
  Grid::Cell se = grid.cell_at(1, 1);

  SECTION("north west cell has valid neighbours") {
    REQUIRE(nw.east() == ne);
    REQUIRE(nw.south() == sw);
    REQUIRE(nw.neighbours().size() == 2);
    REQUIRE(nw.neighbours()[0] == ne);
    REQUIRE(nw.neighbours()[1] == sw);
  }

  SECTION("north east cell has valid neighbours") {
    REQUIRE(ne.west() == nw);
    REQUIRE(ne.south() == se);
    REQUIRE(ne.neighbours().size() == 2);
    REQUIRE(ne.neighbours()[0] == se);
    REQUIRE(ne.neighbours()[1] == nw);
  }

  SECTION("south west cell has valid neighbours") {
    REQUIRE(sw.east() == se);
    REQUIRE(sw.north() == nw);
    REQUIRE(sw.neighbours().size() == 2);
    REQUIRE(sw.neighbours()[0] == nw);
    REQUIRE(sw.neighbours()[1] == se);
  }

  SECTION("south east cell has valid neighbours") {
    REQUIRE(se.west() == sw);
    REQUIRE(se.north() == ne);
    REQUIRE(se.neighbours().size() == 2);
    REQUIRE(se.neighbours()[0] == ne);
    REQUIRE(se.neighbours()[1] == sw);
  }
}

TEST_CASE("a cell correctly reports external neighbours as invalid", "[cell]") {
  using Grid = maze::Grid2d<2, 2>;
  Grid grid;

  SECTION("north west cell reports external neighbours as invalid") {
    Grid::Cell nw = grid.cell_at(0, 0);
    REQUIRE(nw.west().valid() == false);
    REQUIRE(nw.north().valid() == false);
  }

  SECTION("north east cell reports external neighbours as invalid") {
    Grid::Cell ne = grid.cell_at(0, 1);
    REQUIRE(ne.east().valid() == false);
    REQUIRE(ne.north().valid() == false);
  }

  SECTION("south west cell reports external neighbours as invalid") {
    Grid::Cell sw = grid.cell_at(1, 0);
    REQUIRE(sw.west().valid() == false);
    REQUIRE(sw.south().valid() == false);
  }

  SECTION("south west cell reports external neighbours as invalid") {
    Grid::Cell se = grid.cell_at(1, 1);
    REQUIRE(se.east().valid() == false);
    REQUIRE(se.south().valid() == false);
  }
}
