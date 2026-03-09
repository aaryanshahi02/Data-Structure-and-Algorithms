class Solution {
    class Dsu{
        vector<int> parent;

        public:
        Dsu(int n){
            parent.resize(n);
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

            if(pa == pb) return true;

            parent[pb] = pa;
            return false;
        }
    };






public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        Dsu dsu(n+1);

        // vector<pair<int, int>> ans;

        for(auto &e:edges){
            int u = e[0];
            int v = e[1];

            if(dsu.unite(u, v)){
                return {u,v};
            }

            

        }
        return {};
    }
};