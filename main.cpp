//mail: itzhak173@gmail.com

#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"


int main(){

    graph::Graph g(5);
    
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 7);

    std::cout << "\nGraph created" << std::endl;
    g.print_graph();

    std::cout << "\nDeleting edge(1,3)..." << std::endl;
    g.removeEdge(1, 3);
    g.print_graph();
    
    graph::Graph bfs_tree = graph::Algorithms::bfs(g, 0);
    std::cout << "\nBFS tree starting from vertex 0:\n";
    bfs_tree.print_graph();

    graph::Graph dfs_tree = graph::Algorithms::dfs(g, 0);
    std::cout << "\nDFS tree starting from vertex 0:\n";
    dfs_tree.print_graph();

    graph::Graph dijkstra_tree = graph::Algorithms::dijkstra(g, 0);
    std::cout << "\nDijkstra tree starting from vertex 0:\n";
    dijkstra_tree.print_graph();

    graph::Graph prim_tree = graph::Algorithms::prim(g);
    std::cout << "\nPrim's Minimum Spanning Tree starting from vertex 0:\n";
    prim_tree.print_graph();

    graph::Graph kruskal_tree = graph::Algorithms::kruskal(g);
    std::cout << "\nKruskal's Minimum Spanning Tree:\n";
    kruskal_tree.print_graph();

    return 0;
}