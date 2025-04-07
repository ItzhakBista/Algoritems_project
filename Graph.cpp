//mail: itzhak173@gmail.com

#include <iostream>
#include "Graph.hpp"
using namespace graph;


Graph::Graph(int vertices) : numVertices(vertices)
{
    adjacencyList = new Node*[numVertices];
    std::cout << "\nCreating graph..." <<  std::endl;
    for (int i = 0; i < numVertices; i++) {
        adjacencyList[i] = nullptr;
        std::cout << "-Creating vertex " << i << std::endl;
    }
}

Graph::~Graph()
{
    for (int i = 0; i < numVertices; i++) {
        Node* current = adjacencyList[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjacencyList; 
}

void Graph::addEdge(int src, int dest, int weight)
{
    if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
        std::cerr << "Vertex out of bound" << std::endl;
        return;
    }

    Node* newNode = new Node(dest, weight);
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    newNode = new Node(src, weight);
    newNode->next = adjacencyList[dest];
    adjacencyList[dest] = newNode;
}

void Graph::removeEdge(int src, int dest)
{
    if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
        std::cerr << "Error: Vertex out of bound!" << std::endl;
        return;
    }

    Node** current = &adjacencyList[src];
    while (*current != nullptr && (*current)->vertex != dest) {
        current = &((*current)->next);
    }
    if (*current != nullptr) {
        Node* temp = *current;
        *current = (*current)->next;
        delete temp;
    }
    
    current = &adjacencyList[dest];
    while (*current != nullptr && (*current)->vertex != src) {
        current = &((*current)->next);
    }
    if (*current != nullptr) {
        Node* temp = *current;
        *current = (*current)->next;
        delete temp;
    }
}

int Graph::getNumVertices() const {
    return numVertices;
}

Node* Graph::getNeighbors(int vertex) const {
    if (vertex < 0 || vertex >= numVertices) {
        std::cerr << "Invalid vertex index\n";
        return nullptr;
    }
    return adjacencyList[vertex];
}

Edge* Graph::getAllEdges(int& count) const {
    int maxEdges = numVertices * numVertices;
    Edge* edges = new Edge[maxEdges];
    count = 0;

    for (int i = 0; i < numVertices; ++i) {
        Node* current = adjacencyList[i];
        while (current != nullptr) {
            int j = current->vertex;
            if (i < j) {
                edges[count].src = i;
                edges[count].dest = j;
                edges[count].weight = current->weight;
                ++count;
            }
            current = current->next;
        }
    }

    Edge* result = new Edge[count];
    for (int i = 0; i < count; i++) {
        result[i] = edges[i];
    }
    delete[] edges;

    return result;
}


void Graph::print_graph() 
{
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Vertix " << i << ":";
        Node* current = adjacencyList[i];
        while (current != nullptr) {
            std::cout << " -> (" << current->vertex << ", weight: " << current->weight << ")";
            current = current->next;
        }
        std::cout << std::endl;
    }
}
