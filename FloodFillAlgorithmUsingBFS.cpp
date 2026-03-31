//approach - 1
//time complexity - O(m * n)
//space complexity - O(m * n)
class Solution {
public:
    void BFS(vector<vector<int>> &image, vector<vector<int>> &visited, int oldColor, int newColor, int sr, int sc) {
        int m = image.size();
        int n = image[0].size();

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        image[sr][sc] = newColor;
        visited[sr][sc] = 1;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()) {
            int frontRow = q.front().first;
            int frontCol = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int newRow = frontRow + delRow[i];
                int newCol = frontCol + delCol[i];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && image[newRow][newCol] == oldColor && !visited[newRow][newCol]) {
                    image[newRow][newCol] = newColor;
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                } 
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int oldColor = image[sr][sc];
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(image[i][j] == oldColor && !visited[i][j]) {
                    BFS(image, visited, oldColor, color, sr, sc);
                }
            }
        }

        return image;
    }
};
