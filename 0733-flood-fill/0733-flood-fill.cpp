class Solution {
public:

    int rowDir[4] = {-1, 1, 0, 0};
    int colDir[4] = {0, 0, -1, 1};

    bool isValid(int row, int col, int n, int m){
        return(row >= 0 && row < n && col >= 0 && col < m);
    }

    void bfs(vector<vector<int>>& image, int sr, int sc, int newColor, int ogColor){
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        image[sr][sc] = newColor;
        q.push({sr, sc});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int currRow = p.first;
            int currCol = p.second;

            for(int i=0; i<4; i++){
                int newRow = currRow + rowDir[i];
                int newCol = currCol + colDir[i];

                if(isValid(newRow, newCol, n, m) && image[newRow][newCol] == ogColor){
                    image[newRow][newCol] = newColor;
                    q.push({newRow, newCol});
                }
            }
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ogColor = image[sr][sc];

        if(ogColor == color)
            return image;

        bfs(image, sr, sc, color, ogColor);

        return image;
    }
};