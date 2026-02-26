class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, 1e9);

        for(auto &e:times){
            int u = e[0]-1;
            int v = e[1]-1;
            int wt = e[2];

            adj[u].push_back({wt, v});
        }

        pq.push({0, k-1});
        dist[k-1] = 0;

        while(!pq.empty()){
            auto [wt, u] = pq.top();
            pq.pop();

            for(auto &i:adj[u]){
                int w = i.first;
                int v = i.second;

                if (dist[v] > wt + w) {
                    dist[v] = wt + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int d : dist) {
            if (d == 1e9) return -1;
            ans = max(ans, d);
        }

        return ans;

    }
};