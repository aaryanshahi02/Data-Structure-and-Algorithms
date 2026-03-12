class Solution {
    class Dsu{
        vector<int> parent;
        vector<int> rank;

        public:
        Dsu(int n){
            parent.resize(n);
            rank.resize(n, 0);

            for(int i=0; i<n; i++){
                parent[i]=i;
            }
        }

        int find(int x){
            if(parent[x] == x) return x;

            return find(parent[x]);
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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int num = strs[0].size();

        int nums = n;

        Dsu dsu(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int diff = 0;
                for(int k=0; k<num; k++){
                    if(strs[i][k] != strs[j][k]){
                        diff++;
                    }
                }

                if(diff <= 2 && dsu.unite(i, j)){
                    nums--;
                }
            }
        }
        return nums;
    }
};