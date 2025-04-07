//mail: itzhak173@gmail.com

#pragma once

namespace graph
{

    struct Node
    {
        int vertex;
        int weight;
        Node *next;
        Node(int v, int w) : vertex(v), weight(w), next(nullptr) {}
    };

    struct Edge {
        int src;
        int dest;
        int weight;
        Edge() : src(0), dest(0), weight(0) {}
        Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
    };
    

    class Graph
    {
        int numVertices;
        Node **adjacencyList;

    public:
        Graph(int);
        ~Graph();

        void addEdge(int src, int dest, int weight = 1);

        void removeEdge(int src, int dest);

        int getNumVertices() const;

        Node *getNeighbors(int vertex) const;

        Edge* getAllEdges(int& count) const;
        
        void print_graph();

    };

}
