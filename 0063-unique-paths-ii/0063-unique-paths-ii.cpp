class Solution {
public:
    int helper(int r, int c, int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp ){
        if(r<0 || c<0 || r>=n || c>=m || obstacleGrid[r][c]==1){
            return 0;
        }
        if(r==n-1 && c==m-1)
        {
            return 1;
        }
         if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int ans=0;
        int dr[]={1, 0};
        int dc[]={0, 1};
        for(int i=0; i<2; i++){
            int nrow=r+dr[i];
            int ncol=c+dc[i];
            ans+=helper(nrow, ncol, n, m, obstacleGrid, dp);
        }
         return dp[r][c]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n= obstacleGrid.size();
        int m= obstacleGrid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return helper(0, 0, n, m, obstacleGrid, dp);
    }
};