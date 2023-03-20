class Solution {
public:
    int getMaximumGenerated(int n) {
 int dp[n+1];
        if(n==0){return 0;}
        if(n==1){return 1;}
        dp[0]=0;
        dp[1]=1;
        int maxi=dp[1];
        for(int i=2;i<n+1;i++)
        {
            if(i%2==0)
            {
                dp[i]=dp[i/2];
            }
            else
            {
                dp[i]=dp[i/2]+dp[(i/2)+1];
            }
            
            if(maxi<dp[i])
            {
                maxi=dp[i];
            }
            
        }
        
        return maxi;
    }
};

