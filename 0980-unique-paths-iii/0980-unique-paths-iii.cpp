class Solution {
public:
    int helper(int x1, int y1, int x2, int y2, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp, int emptyCount) {
        if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m || grid[x1][y1] == -1) {
            return 0;
        }
        if (x1 == x2 && y1 == y2) {
            return (emptyCount == 0) ? 1 : 0;
        }
        
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int ans = 0;
        grid[x1][y1]=-1;
        for (int i = 0; i < 4; i++) {
            int nrow = x1 + dr[i];
            int ncol = y1 + dc[i];
            ans += helper(nrow, ncol, x2, y2, n, m, grid, dp, emptyCount - 1);
        }
        grid[x1][y1]=0;
        return dp[x1][y1] = ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int x1, y1, x2, y2;
        
        // Find the starting and ending squares
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    x1 = i;
                    y1 = j;
                } else if (grid[i][j] == 2) {
                    x2 = i;
                    y2 = j;
                }
            }
        }
        
        int emptyCount = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    emptyCount++;
                }
            }
        }
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(x1, y1, x2, y2, n, m, grid, dp, emptyCount);
    }
};