//mail: itzhak173@gmail.com

#pragma once

class UnionFind {
    private:
        int* parent;
        int* rank;
    
    public:
        UnionFind(int n) {
            parent = new int[n];
            rank = new int[n]();
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
    
        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }
    
        int find(int v) {
            if (parent[v] != v) {
                parent[v] = find(parent[v]);
            }
            return parent[v];
        }
    
        void unionSets(int v1, int v2) {
            int root1 = find(v1);
            int root2 = find(v2);
            if (root1 != root2) {
                if (rank[root1] > rank[root2]) {
                    parent[root2] = root1;
                } else if (rank[root1] < rank[root2]) {
                    parent[root1] = root2;
                } else {
                    parent[root2] = root1;
                    rank[root1]++;
                }
            }
        }
    };