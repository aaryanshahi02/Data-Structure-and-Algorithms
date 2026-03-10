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
    int makeConnected(int n, vector<vector<int>>& connections) {
       int extra = 0;

        Dsu dsu(n);

        for(auto &e:connections){
            int u = e[0];
            int v = e[1];
            

            if(dsu.unite(u, v)){
                extra++;
            }
        }

        int components = 0;
        for(int i=0; i<n; i++){
            if(dsu.find(i) == i){
                components++;
            }
        }
        if(extra < components-1) return -1;

        return components - 1;
    }
};