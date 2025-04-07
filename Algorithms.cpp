//mail: itzhak173@gmail.com

#include "Algorithms.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"
#include <climits>

namespace graph {

    Graph Algorithms::bfs(const Graph& g, int start) {
        int n = g.getNumVertices();
        Graph tree(n);
        bool* visited = new bool[n]();
        Queue<int> q;
        visited[start] = true;
        q.enqueue(start);

        while (!q.isEmpty()) {
            int v = q.dequeue();
            Node* neighbor = g.getNeighbors(v);
            while (neighbor) {
                if (!visited[neighbor->vertex]) {
                    visited[neighbor->vertex] = true;
                    tree.addEdge(v, neighbor->vertex, neighbor->weight);
                    q.enqueue(neighbor->vertex);
                }
                neighbor = neighbor->next;
            }
        }

        delete[] visited;
        return tree;
    }

    void Algorithms::dfsHelper(const Graph& g, Graph& tree, bool* visited, int v) {
        visited[v] = true;
        Node* neighbor = g.getNeighbors(v);
        while (neighbor) {
            if (!visited[neighbor->vertex]) {
                tree.addEdge(v, neighbor->vertex, neighbor->weight);
                dfsHelper(g, tree, visited, neighbor->vertex);
            }
            neighbor = neighbor->next;
        }
    }

    Graph Algorithms::dfs(const Graph& g, int start) {
        int n = g.getNumVertices();
        Graph tree(n);
        bool* visited = new bool[n]();
        Algorithms::dfsHelper(g, tree, visited, start);
        delete[] visited;
        return tree;
    }

    Graph Algorithms::dijkstra(const Graph& g, int start) {
        int n = g.getNumVertices();
        Graph tree(n);
        int* dist = new int[n];
        bool* visited = new bool[n]();
        int* parent = new int[n];
    
        for (int i = 0; i < n; i++) {
            dist[i] = INT_MAX;
            parent[i] = -1;
        }
    
        dist[start] = 0;
    
        for (int count = 0; count < n - 1; count++) {
            int minDist = INT_MAX, u = -1;
            
            for (int v = 0; v < n; v++) {
                if (!visited[v] && dist[v] < minDist) {
                    minDist = dist[v];
                    u = v;
                }
            }
    
            if (u == -1) break;
    
            visited[u] = true;
    
            Node* neighbor = g.getNeighbors(u);
            while (neighbor != nullptr) {
                int newDist = dist[u] + neighbor->weight;
    
                if (newDist < dist[neighbor->vertex]) {
                    dist[neighbor->vertex] = newDist;
                    parent[neighbor->vertex] = u;
                    tree.addEdge(u, neighbor->vertex, neighbor->weight);
                }
    
                neighbor = neighbor->next;
            }
        }
    
        delete[] visited;
        delete[] dist;
        delete[] parent;
    
        return tree;
    }

    Graph Algorithms::prim(const Graph& g) {
        int n = g.getNumVertices();
        Graph tree(n);
        int* key = new int[n];
        bool* inMST = new bool[n]();
        int* parent = new int[n];

        for (int i = 0; i < n; i++) {
            key[i] = INT_MAX;
            parent[i] = -1;
        }

        key[0] = 0;

        for (int count = 0; count < n - 1; count++) {
            int u = -1;
            for (int v = 0; v < n; v++) {
                if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                    u = v;
                }
            }

            inMST[u] = true;
            Node* neighbor = g.getNeighbors(u);
            while (neighbor) {
                int v = neighbor->vertex;
                int weight = neighbor->weight;
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
                neighbor = neighbor->next;
            }
        }

        for (int i = 1; i < n; i++) {
            if (parent[i] != -1) {
                tree.addEdge(parent[i], i, key[i]);
            }
        }

        delete[] key;
        delete[] inMST;
        delete[] parent;
        return tree;
    }

    Graph Algorithms::kruskal(const Graph& g) {
        int n = g.getNumVertices();
        Graph tree(n);
        UnionFind uf(n);
    
        int edgeCount = 0;
        Edge* edges = g.getAllEdges(edgeCount);
    
        for (int i = 0; i < edgeCount - 1; i++) {
            for (int j = i + 1; j < edgeCount; j++) {
                if (edges[j].weight < edges[i].weight) {
                    Edge temp = edges[i];
                    edges[i] = edges[j];
                    edges[j] = temp;
                }
            }
        }
    
        for (int i = 0; i < edgeCount; i++) {
            int src = edges[i].src;
            int dest = edges[i].dest;
            if (uf.find(src) != uf.find(dest)) {
                uf.unionSets(src, dest);
                tree.addEdge(src, dest, edges[i].weight);
            }
        }
    
        delete[] edges;
    
        return tree;
    }
    

}
