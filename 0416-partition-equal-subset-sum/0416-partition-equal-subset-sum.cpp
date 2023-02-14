class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int totsum=0;
        for(int i=0; i<n; i++)
            totsum += nums[i];
        if(totsum%2==1)
            return false;
        else{
            int k = totsum/2;
            vector<vector<bool>> dp(n, vector<bool>(k+1, false));
            for(int i=0; i<n; i++){
                dp[i][0] = true;
            }
            if(nums[0]<=k)
                dp[0][nums[0]]=true;
             for(int ind=1; ind<n; ind++){
                  for(int target=1; target<=k; target++){
                      bool notTaken = dp[ind-1][target];
                      bool Taken = false;
                     if(nums[ind]<=target)
                         Taken = dp[ind-1][target-nums[ind]];
                      dp[ind][target] = notTaken || Taken;
        }
    }
            return dp[n-1][k];
        }
    }
};