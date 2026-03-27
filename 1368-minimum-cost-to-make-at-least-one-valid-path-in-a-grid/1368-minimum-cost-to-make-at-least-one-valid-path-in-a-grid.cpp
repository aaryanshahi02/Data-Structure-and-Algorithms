class Solution {
public:
    int n, m;

    vector<int> rowDir = {0, 0, 1, -1};
    vector<int> colDir = {1, -1, 0, 0};
    
    bool isValid(int r, int c) {
        return (r >= 0 && c >= 0 && r < n && c < m);
    }
    
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;
        
        pq.push({0, {0,0}});
        dist[0][0] = 0;
        
        while(!pq.empty()) {
            auto [cost, pos] = pq.top();
            auto [r, c] = pos;
            pq.pop();
            
            if(cost > dist[r][c]) continue;
            
            for(int i = 0; i < 4; i++) {
                int nr = r + rowDir[i];
                int nc = c + colDir[i];
                
                if(!isValid(nr, nc)) continue;
                
                int newCost = cost + (grid[r][c] == i+1 ? 0 : 1);
                
                if(newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, {nr, nc}});
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};