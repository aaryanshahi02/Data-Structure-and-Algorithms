class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector<vector<int>> dist(n, vector<int> (k+2, 1e9));

        for(auto &e:flights){
            int from = e[0];
            int to = e[1];
            int wt = e[2];
            adj[from].push_back({wt, to});
        }
        pq.push({0, src, 0});
        dist[src][0] = 0;

        while(!pq.empty()){
            auto[d, node, stops] = pq.top();
            pq.pop();

            if(stops > k) continue;

            if(node == dst) continue;

            for(auto &it : adj[node]){
                int dis = it.first;
                int neigh = it.second;

                int newDist = dis + d;

                if(stops + 1 <= k+1 && newDist < dist[neigh][stops+1]){
                    dist[neigh][stops+1] = newDist;
                    
                    pq.push({newDist, neigh, stops+1});
                }

            }
        }
        
        int ans = 1e9;
for(int i = 0; i <= k+1; i++){
    ans = min(ans, dist[dst][i]);
}

return ans == 1e9 ? -1 : ans;
    }
};