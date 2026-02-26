class Solution {
public:

    int rowDir[4] = {-1, 1, 0, 0};
    int colDir[4] = {0, 0, -1, 1};

    bool isValid(int row, int col, int n){
        return (row >= 0 && row < n && col >= 0 && col < n);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;

        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while(!pq.empty()){
            auto [time, cell] = pq.top();
            pq.pop();

            int currRow = cell.first;
            int currCol = cell.second;

            if(time > dist[currRow][currCol]) continue;

            if(currRow == n-1 && currCol == n-1) return time;

            for(int i=0; i<4; i++){
                int newRow = currRow + rowDir[i];
                int newCol = currCol + colDir[i];

                if(isValid(newRow, newCol, n)){
                    int newTime = max(time, grid[newRow][newCol]);

                    if(newTime < dist[newRow][newCol]){
                        dist[newRow][newCol] = newTime;
                        pq.push({newTime, {newRow, newCol}});
                    }
                }
            }
        }
        return 0;
    }
};