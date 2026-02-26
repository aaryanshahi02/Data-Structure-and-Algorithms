class Solution {
public:

    int rowDir[4] = {-1, 1, 0, 0};
    int colDir[4] = {0, 0, -1, 1};

    bool isValid(int row, int col, int n, int m){
        return(row >= 0 && row<n && col >= 0 && col < m);
    }


    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        

        pq.push({0, {0,0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto [effort, cell] = pq.top();
            pq.pop();

            int currRow = cell.first;
            int currCol = cell.second;

            if(currRow == n-1 && currCol == m-1) return effort;

            for(int i=0; i<4; i++){
                int newRow = currRow + rowDir[i];
                int newCol = currCol + colDir[i];

                if(isValid(newRow, newCol, n, m)){
                    int edgeWt = abs(heights[currRow][currCol] - heights[newRow][newCol]);
                    int newEffort = max(edgeWt, effort);

                    if(newEffort < dist[newRow][newCol]){
                        dist[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }

        return 0;
    }
};