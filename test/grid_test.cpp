#include "catch.hpp"
#include "maze/graph/grid2d.hpp"

TEST_CASE("a grid correctly reports its row and column sizes", "[grid]") {
  maze::Grid2d<3, 4> grid;
  REQUIRE(grid.rows() == 3);
  REQUIRE(grid.columns() == 4);
}

TEST_CASE("an empty grid is valid but its cells are not", "[grid]") {
  maze::Grid2d<0, 0> grid;
  SECTION("querying a cell yields an invalid result") {
    REQUIRE(grid.cell_at(0, 0).valid() == false);
  }

  SECTION("the rows and columns are zero") {
    REQUIRE(grid.rows() == 0);
    REQUIRE(grid.columns() == 0);
  }
}

TEST_CASE("a non-empty grid containts cells", "[grid]") {
  maze::Grid2d<2, 3> grid;
  for (int r = 0; r < grid.rows(); ++r) {
    for (int c = 0; c < grid.columns(); ++c) {
      REQUIRE(grid.cell_at(r, c).valid() == true);
    }
  }
}

TEST_CASE("randomly selected cells are valid", "[grid]") {
  maze::Grid2d<10, 10> grid;
  size_t valid_count = 0;

  const size_t ITERATIONS = 1000;
  for (size_t i = 0; i < ITERATIONS; ++i) {
    if (grid.random_cell().valid()) {
      ++valid_count;
    }
  }
  REQUIRE(valid_count == ITERATIONS);
}

TEST_CASE("randomly selected cells have a reasonable distribution", "[grid]") {
  maze::Grid2d<4, 4> grid;
  std::array<int, grid.size()> hit_per_cell = {};

  const size_t ITERATIONS = 1000;
  for (size_t i = 0; i < ITERATIONS; ++i) {
    ++hit_per_cell[grid.random_cell().index()];
  }

  const size_t TOLERANCE = 1000 / grid.size();
  for (size_t i = 0; i < grid.size() - 1; ++i) {
    int diff = abs(hit_per_cell[i] - hit_per_cell[i + 1]);
    REQUIRE(diff < TOLERANCE);
  }
}
