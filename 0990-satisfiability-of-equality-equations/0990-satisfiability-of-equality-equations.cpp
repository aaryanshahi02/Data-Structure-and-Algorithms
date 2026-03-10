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

        void unite(int a, int b){
            int pa = find(a);
            int pb = find(b);

            if(pa == pb) return;

            if(rank[pa] > rank[pb]){
                parent[pb] = pa;           
            }
            else if(rank[pb] > rank[pa]){
                parent[pa] = pb;
            }
            else{
                parent[pb] = pa;
                rank[pa]++;
            }
        }


    };







public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();

        Dsu dsu(26);

        for(int i=0; i<n; i++){
            string curr = equations[i];

            if(curr[1] == '='){
                int a = curr[0] - 'a';
                int b = curr[3] - 'a';
                dsu.unite(a, b);
            }
        }

        for(int i=0; i<n; i++){
            string curr = equations[i];

            if(curr[1] == '!'){
                int a = curr[0] - 'a';
                int b = curr[3] - 'a';

                int pa = dsu.find(a);
                int pb = dsu.find(b);

                if(pa == pb) return false;
            }
        }
        return true;

    }
};