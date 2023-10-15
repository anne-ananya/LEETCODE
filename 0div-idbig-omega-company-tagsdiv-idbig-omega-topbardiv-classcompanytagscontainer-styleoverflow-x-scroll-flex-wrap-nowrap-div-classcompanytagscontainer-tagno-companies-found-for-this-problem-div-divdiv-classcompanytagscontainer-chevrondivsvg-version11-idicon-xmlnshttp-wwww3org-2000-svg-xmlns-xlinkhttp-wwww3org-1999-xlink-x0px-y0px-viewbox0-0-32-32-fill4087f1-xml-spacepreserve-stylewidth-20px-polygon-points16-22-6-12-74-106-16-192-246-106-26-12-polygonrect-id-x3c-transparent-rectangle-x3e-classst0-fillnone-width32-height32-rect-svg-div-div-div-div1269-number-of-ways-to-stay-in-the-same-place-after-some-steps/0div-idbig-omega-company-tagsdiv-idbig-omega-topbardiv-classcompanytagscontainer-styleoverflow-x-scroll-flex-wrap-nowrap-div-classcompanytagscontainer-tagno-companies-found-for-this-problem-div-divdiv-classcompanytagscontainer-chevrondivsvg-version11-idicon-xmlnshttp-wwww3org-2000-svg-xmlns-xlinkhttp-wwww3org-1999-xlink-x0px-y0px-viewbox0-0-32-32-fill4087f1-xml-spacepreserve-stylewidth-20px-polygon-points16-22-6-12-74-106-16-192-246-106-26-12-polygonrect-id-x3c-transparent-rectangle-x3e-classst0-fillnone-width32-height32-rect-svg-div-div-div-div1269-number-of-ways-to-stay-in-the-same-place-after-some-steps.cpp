class Solution {
public:
    int MOD = 1000000007;

    long long f(long long i, long long steps, int arrLen, vector<vector<long long>>& dp) {
        if (i < 0 || i == arrLen)
            return 0;

        if (steps == 0 && i == 0)
            return 1;
        if (steps == 0 && i != 0)
            return 0;

        if (dp[i][steps] != -1)
            return dp[i][steps] % MOD;

        long long left = f(i - 1, steps - 1, arrLen, dp) % MOD;
        long long stay = f(i, steps - 1, arrLen, dp) % MOD;
        long long right = f(i + 1, steps - 1, arrLen, dp) % MOD;

        return dp[i][steps] = (left + stay + right) % MOD;
    } 

    int numWays(int steps, int arrLen) {
        arrLen= min(arrLen, steps);
        vector<vector<long long>> dp(arrLen, vector<long long>(steps + 1, -1));

        return f(0, steps, arrLen, dp) % MOD;
    }
};
