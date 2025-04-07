//mail: itzhak173@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

TEST_CASE("DFS test") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);

    Graph tree = Algorithms::dfs(g, 0);
    tree.print_graph();
}

TEST_CASE("BFS test") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);

    Graph tree = Algorithms::bfs(g, 0);
    tree.print_graph();
}

TEST_CASE("Prim's Algorithm test") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);

    Graph tree = Algorithms::prim(g);
    tree.print_graph();
}

TEST_CASE("Dijkstra test") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);
    g.addEdge(0, 4, 100);

    Graph tree = Algorithms::dijkstra(g, 0);
    tree.print_graph();
}

TEST_CASE("Kruskal's Algorithm test") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);
    g.addEdge(0, 4, 100);
    g.addEdge(1, 3, 50);
    
    Graph mst = Algorithms::kruskal(g);
    mst.print_graph();
}

