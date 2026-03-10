class Solution {

    class Dsu{
        vector<int> parent;
        vector<int> rank;
        int components;

        public:
        Dsu(int n){
            parent.resize(n);
            rank.resize(n, 0);
            components = n;

            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if(parent[x] == x) return x;

            return find(parent[x]);
        }

        void unite(int a, int b){
            int pa = find(a);
            int pb = find(b);

            if(pa == pb) return;

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
            components--;
        }
        int getComponents(){
            return components;
        }
    };









public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        Dsu dsu(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int u = stones[i][0];
                int v = stones[i][1];

                int prevU = stones[j][0];
                int prevV = stones[j][1];

                if(u == prevU || v == prevV){
                    dsu.unite(i, j);
                }
            }
        }
        return n - dsu.getComponents();
    }
};