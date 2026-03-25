class UnionFind {
    vector<int> parent, sz;
public:
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }
    
    int find(int i) {
        return parent[i] == i ? i : (parent[i] = find(parent[i]));
    }
    
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        UnionFind uf(n);
        int components = n;

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });

        for (const auto& edge : edges) {
            if (uf.unite(edge[0], edge[1])) {
                components--;
            }
            if (components < k) {
                return edge[2];
            }
        }

        return 0;
    }
};