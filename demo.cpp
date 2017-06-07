#include <iostream>
#include "maze/graph/grid.hpp"

using namespace std;
using namespace maze;

int main()
{
  Grid g(10, 10);
  cout << "insert ";
  cout << g.rows() << "x" << g.columns();
  cout << " maze here!" << endl;
  return 0;
}
