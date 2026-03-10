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
            }
    };





public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
     int n = accounts.size();

        Dsu dsu(n);

        unordered_map<string,int> mp;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){

                string mail = accounts[i][j];

                if(mp.find(mail)==mp.end())
                    mp[mail]=i;

                else
                    dsu.unite(i, mp[mail]);
            }
        }

        unordered_map<int, set<string>> merged;

        for(auto &it : mp){
            string mail = it.first;
            int idx = it.second;

            int parent = dsu.find(idx);

            merged[parent].insert(mail);
        }

        vector<vector<string>> ans;

        for(auto &it : merged){

            int idx = it.first;

            vector<string> temp;

            temp.push_back(accounts[idx][0]);

            for(auto &mail : it.second)
                temp.push_back(mail);

            ans.push_back(temp);
        }

        return ans;
    }
};