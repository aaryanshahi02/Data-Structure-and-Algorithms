class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
        
        pq.push({0, {0,0}});
        dist[0][0] = 0;

        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        while(!pq.empty()) {
            auto [cost, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();

            if(cost > dist[x][y]) continue;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                
                int newCost = cost + (grid[x][y] == i+1 ? 0 : 1);
                
                if(newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};