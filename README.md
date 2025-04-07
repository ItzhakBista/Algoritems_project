# Algoritems_project
First assignment in course: System programing 2.

# Graph Algorithms Project

This project implements various graph algorithms in C++ for an undirected graph. The goal of the project is to explore fundamental graph algorithms such as Depth-First Search (DFS), Breadth-First Search (BFS), Dijkstra's Algorithm, Prim's Algorithm, Kruskal's Algorithm, and Union-Find. The algorithms are implemented using custom data structures and without the use of the C++ Standard Library (STL).

## Table of Contents

- [Project Description](#project-description)
- [Classes and Files](#classes-and-files)
  - [Graph Class](#graph-class)
  - [Algorithms Class](#algorithms-class)
  - [Queue Class](#queue-class)
  - [UnionFind Class](#unionfind-class)
- [Compilation and Execution](#compilation-and-execution)
- [Testing](#testing)

## Project Description

This project aims to implement basic graph algorithms such as BFS, DFS, Dijkstra, Prim, Kruskal, and a Union-Find data structure. The algorithms are designed to work with an undirected graph and are tested using the Doctest framework. The project avoids using the C++ Standard Library and implements the required data structures from scratch.

## Classes and Files

### Graph Class

- **Graph.hpp** and **Graph.cpp**
  - This class represents an undirected graph using an adjacency list. It contains methods to add edges, print the graph, and access its nodes.
  - The graph uses an internal structure of custom nodes and adjacency lists.
  - The graph can be represented and manipulated using basic operations like adding edges, checking neighbors, and printing the graph.

### Algorithms Class

- **Algorithms.hpp** and **Algorithms.cpp**
  - This class contains the graph algorithms: DFS, BFS, Dijkstra, Prim, and Kruskal.
  - Each algorithm operates on a graph and returns the resultant graph or the shortest path tree (in the case of Dijkstra).
  - The algorithms are implemented with careful attention to the constraints of not using the C++ STL.

### Queue Class

- **Queue.hpp**
  - A custom queue implementation using arrays.
  - Supports basic queue operations like enqueue, dequeue, and checking if the queue is empty.

### UnionFind Class

- **UnionFind.hpp**
  - This class implements the Union-Find (Disjoint-Set) data structure.
  - It supports operations like `find`, `unite`, and path compression for efficient set operations.

## Compilation and Execution

To compile the project, run the following commands:

1. **Compiling the code:**
   
    Run the command "make".
    This command will compile the program.

3. **Running the program:**
   
    Run the command "make Main".
    This command will run the program.

4. **Running tests (using Doctest):**

    Run the command "make test".
    This command will run all the tests written using the Doctest framework.

5. **Checking for memory leaks (using Valgrind)**

    Run the command "make valgrind".
    This command will check if there are any memory leaks, using Valgrind.

6. **Deleting the compiled files**

    Run the command "make clean".
    This command will delete the files that were created during the compilation of our program.

## Testing

The project uses the Doctest testing framework to write unit tests for the implemented algorithms. Some of the tests included are for the following algorithms:

- DFS: Tests Depth-First Search by adding edges and printing the resultant graph.

- BFS: Tests Breadth-First Search similarly to DFS.

- Prim's Algorithm: Tests Prim's minimum spanning tree algorithm.

- Dijkstra's Algorithm: Tests Dijkstra's shortest path tree algorithm.

- Kruskal's Algorithm: Tests Kruskal's algorithm for finding the minimum spanning tree (MST).



