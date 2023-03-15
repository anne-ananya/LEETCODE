class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for (int j=0; j<=m; j++) dp[0][j] = 0;

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0 + max(dp[i][j-1], dp[i-1][j]);
            }
        }
        int i = str1.size();
        int j = str2.size();
        string ans = "";
        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                ans += str1[i-1];
                i--;
                j--;
            }
            else if (dp[i][j-1] >  dp[i-1][j]) {
                ans += str2[j-1];
                j--;
            }
            else {
                ans += str1[i-1];
                i--;
            }
        }
        while (i > 0) {
            ans += str1[i-1];
            i--;
        }
        while (j > 0) {
            ans += str2[j-1];
            j--;
        };
        reverse(begin(ans), end(ans));
        return ans;
    }
};