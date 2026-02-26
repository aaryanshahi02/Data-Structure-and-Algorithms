class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({p, v});
            adj[v].push_back({p, u});  
        }

        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;

        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start_node});

        while(!pq.empty()){
            auto [prob, u] = pq.top();
            pq.pop();

            if (u == end_node) return prob;

            if (prob < dist[u]) continue;

            for(auto &it:adj[u]){
                double p = it.first;
                int v = it.second;

                double newProb  = prob*p;
                if(newProb > dist[v]){
                    dist[v] = newProb;
                    pq.push({newProb, v});
                }
                
            }
        }
        return 0.0;
    }
};