#ifndef MAZE_ALGO_RECURSIVE_BACKTRACKER_HPP
#define MAZE_ALGO_RECURSIVE_BACKTRACKER_HPP

#include <vector>
#include <stack>

namespace maze {

//------------------------------------------------------------------------------
//! Implementation of recursive backtracker maze-generating algorithm.
//------------------------------------------------------------------------------
template <typename Graph>
class RecursiveBacktracker

  //! Generate a maze given the starting cell.
  //! Chooses a random cell if no cell is specified.
  //! See chapter 5 of 'Mazes for Programmers' by Jamis Buck for implementation details.
  constexpr static generate(Graph graph, Graph::Cell start = Graph::Cell()) {
    if (!start.valid()) {
      start = Graph.random_cell();
    }

    std::stack<Graph::Cell> stack;
    stack.push_back(start);

    while (!stack.empty())
    {
      auto current = stack.back();

      // Select only the neighbours with no links
      auto ns = current.neighbours();
      ns.erase(
        std::remove_if(ns.begin(), ns.end(),
          [](Cell n) {
            return !a.links.empty();
          }
        )
      );

      if (ns.empty()) {
        stack.pop();
      }
      else {
        auto neighbour = ns.sample(); // TODO return Graph::Cell
        current.link(neighbour); // TODO implement cell link
        stack.push(neighbour);
      }
    }
  }
};

//------------------------------------------------------------------------------
} // namespace maze

#endif // MAZE_ALGO_RECURSIVE_BACKTRACKER_HPP
