class Solution {
public:
    int minCost(int startIdx, int endIdx, int remainingChanges, vector<int>& diffPositions, int targetChanges, vector<vector<int>>& dp) {
        if (startIdx >= endIdx) {
            return 0;
        }
        
        if (remainingChanges < 0) {
            return 0;
        }
        
        if (startIdx > endIdx) {
            return 0;
        }
        
        if (dp[startIdx][endIdx] != -1) {
            return dp[startIdx][endIdx];
        }
        
        int addOperationCost = diffPositions[startIdx + 1] - diffPositions[startIdx] + minCost(startIdx + 2, endIdx, remainingChanges, diffPositions, targetChanges, dp);
        
        int removeOperationCost = diffPositions[endIdx] - diffPositions[endIdx - 1] + minCost(startIdx, endIdx - 2, remainingChanges, diffPositions, targetChanges, dp);
        
        int changeOperationCost = targetChanges + minCost(startIdx + 1, endIdx - 1, remainingChanges - 2, diffPositions, targetChanges, dp);
        
        return dp[startIdx][endIdx] = min(addOperationCost, min(removeOperationCost, changeOperationCost));
    }
    
    int minOperations(string s1, string s2, int targetChanges) {
        int n = s1.size();
        vector<int> diffPositions;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); // Initialize the dynamic programming table
        
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diffPositions.push_back(i);
            }
        }
        
        int numDifferences = diffPositions.size();
        
        if (numDifferences % 2 != 0) {
            return -1;
        }
        
        int result = minCost(0, numDifferences - 1, numDifferences, diffPositions, targetChanges, dp);
        return result;
    }
};
