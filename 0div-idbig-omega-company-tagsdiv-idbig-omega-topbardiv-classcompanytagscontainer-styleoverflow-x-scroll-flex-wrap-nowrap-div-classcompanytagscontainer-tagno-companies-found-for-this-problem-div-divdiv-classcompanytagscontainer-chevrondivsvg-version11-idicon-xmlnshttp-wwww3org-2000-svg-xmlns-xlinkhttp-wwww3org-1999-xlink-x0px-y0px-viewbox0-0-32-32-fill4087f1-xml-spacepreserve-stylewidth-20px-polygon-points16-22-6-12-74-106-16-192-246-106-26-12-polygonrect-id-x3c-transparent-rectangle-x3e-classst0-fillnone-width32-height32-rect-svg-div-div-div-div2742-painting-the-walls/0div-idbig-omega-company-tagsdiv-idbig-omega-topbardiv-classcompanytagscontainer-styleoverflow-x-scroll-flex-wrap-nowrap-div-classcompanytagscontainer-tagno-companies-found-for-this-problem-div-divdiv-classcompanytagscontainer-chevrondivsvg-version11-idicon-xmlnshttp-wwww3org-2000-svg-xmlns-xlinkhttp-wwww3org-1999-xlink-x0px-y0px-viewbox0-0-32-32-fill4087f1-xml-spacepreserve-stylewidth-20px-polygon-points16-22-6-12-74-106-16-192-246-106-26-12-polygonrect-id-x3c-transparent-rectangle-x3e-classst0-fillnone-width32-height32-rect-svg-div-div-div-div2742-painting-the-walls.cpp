class Solution {
public:
    int f(int ind, int rem, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp) {
        if (rem <= 0)
            return 0;
        if (ind <0)
            return 1e9;
        if (dp[ind][rem] != -1)
            return dp[ind][rem];
        int paint = cost[ind] + f(ind - 1, rem - 1 - time[ind], cost, time, dp);
        int not_paint = f(ind-1, rem, cost, time, dp);
        dp[ind][rem] = min(paint, not_paint);
        return dp[ind][rem];
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(n-1, n, cost, time, dp);
    }
};
