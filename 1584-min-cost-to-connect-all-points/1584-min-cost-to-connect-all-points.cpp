class Solution {
    class Dsu{
        vector<int> parent;
        vector<int> rank;

        public:
        Dsu(int n){
            parent.resize(n);
            rank.resize(n, 0);

            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }

        int find(int i){
            if(parent[i] == i) return i;

            return find(parent[i]);
        }

        bool unite(int a, int b){
            int pa = find(a);
            int pb = find(b);

            if(pa == pb) return false;

            if(rank[pa] > rank[pb]){
                parent[pb] = pa;
            }

            else if(rank[pa] < rank[pb]){
                parent[pa] = pb;
            }

            else{
                parent[pb] = pa;
                rank[pa]++;
            }

            return true;
        }
    };

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        int cost = 0;
        Dsu dsu(n);


        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int u = i;
                int v = j;

                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        for(auto &e:edges){
            int wt = e[0];
            int u = e[1];
            int v = e[2];

            if(dsu.unite(u, v)){
                cost+=wt;
            }
        }
        return cost;
    }
};