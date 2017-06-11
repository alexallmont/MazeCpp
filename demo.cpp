#include <iostream>
#include "maze/graph/grid2d.hpp"

using namespace std;
using namespace maze;

int main()
{
  Grid2d<4, 3> g;
  cout << "insert ";
  cout << g.rows() << "x" << g.columns();
  cout << " maze here!" << endl;
  return 0;
}
