class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int t = e[2];
            adj[u].push_back({t, v});
            adj[v].push_back({t, u});
        }

        vector<vector<int>> dist(n, vector<int>(maxTime + 1, 1e9));

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        pq.push({passingFees[0], 0, 0});
        dist[0][0] = passingFees[0];

        while (!pq.empty()) {
            auto [cost, node, time] = pq.top();
            pq.pop();

            if (time > maxTime) continue;

            if (node == n - 1) return cost;

            for (auto &it : adj[node]) {
                int edgeTime = it.first;
                int neigh = it.second;

                int newTime = time + edgeTime;
                if (newTime > maxTime) continue;

                int newCost = cost + passingFees[neigh];

                if (newCost < dist[neigh][newTime]) {
                    dist[neigh][newTime] = newCost;
                    pq.push({newCost, neigh, newTime});
                }
            }
        }

        return -1;
    }
};