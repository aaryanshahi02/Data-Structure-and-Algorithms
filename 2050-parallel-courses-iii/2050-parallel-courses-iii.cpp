class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);

        for (auto &r : relations) {
            int u = r[0] - 1;
            int v = r[1] - 1;
            adj[u].push_back(v);
            indeg[v]++;
        }

        vector<int> finishTime(n, 0);

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                finishTime[i] = time[i];
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                finishTime[v] = max(finishTime[v],finishTime[u] + time[v]);

                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, finishTime[i]);
        }

        return ans;
    }
};