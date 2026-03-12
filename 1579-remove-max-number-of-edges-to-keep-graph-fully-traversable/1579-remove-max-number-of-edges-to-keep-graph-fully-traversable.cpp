class Solution {
    class Dsu {
        vector<int> parent;
        vector<int> rank;

    public:
        Dsu(int n) {
            parent.resize(n+1);
            rank.resize(n+1, 0);

            for (int i = 1; i <=n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        }

        bool unite(int a, int b) {

            int pa = find(a);
            int pb = find(b);

            if(pa == pb) return false;

            if (rank[pa] > rank[pb]) {
                parent[pb] = pa;
            } else if (rank[pa] < rank[pb]) {
                parent[pa] = pb;
            } else {
                parent[pb] = pa;
                rank[pa]++;
            }
            return true;
        }
    };

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {


        Dsu alice(n);
        Dsu bob(n);

        int usedEdges = 0;


        for (auto& e : edges) {
            if (e[0] == 3) {
                bool a = alice.unite(e[1], e[2]);
                bool b = bob.unite(e[1], e[2]);
                if (a || b)
                    usedEdges++;
            }
        }

        for (auto& e : edges) {
            if (e[0] == 1) {
                if (alice.unite(e[1], e[2])) {
                    usedEdges++;
                }
            }
        }

        for (auto& e : edges) {
            if (e[0] == 2) {
                if (bob.unite(e[1], e[2])) {
                    usedEdges++;
                }
            }
        }

        int compA = 0, compB = 0;
        for (int i = 1; i <= n; i++) {
            if (alice.find(i) == i)
                compA++;
            if (bob.find(i) == i)
                compB++;
        }

        if (compA > 1 || compB > 1)
            return -1;




        return edges.size() - usedEdges;
    }
};