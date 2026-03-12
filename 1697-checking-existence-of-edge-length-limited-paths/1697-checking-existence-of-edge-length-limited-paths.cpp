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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        Dsu dsu (n);

        for(int i=0; i<queries.size(); i++){
            queries[i].push_back(i);
        }

        sort(edgeList.begin(), edgeList.end(),
            [](auto &a, auto &b){
                return a[2] < b[2];
            });

        sort(queries.begin(), queries.end(),
            [](auto &a, auto &b){
                return a[2] < b[2];
            });

        vector<bool> ans(queries.size());
        int j = 0;

        for(auto &q:queries){
            int u = q[0];
            int v = q[1];
            int limit = q[2];
            int idx = q[3];

            while(j<edgeList.size() && edgeList[j][2] < limit){
                dsu.unite(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            ans[idx] = (dsu.find(u) == dsu.find(v));
        }

        
        return ans;
    }
};