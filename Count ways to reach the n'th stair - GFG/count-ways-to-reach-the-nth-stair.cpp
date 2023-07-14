//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    const int MOD = 1000000007;
    int fib(int n, int dp[])
{
    if (n <= 1)
        return dp[n] = 1;
 
    if (dp[n] != -1) {
        return dp[n];
    }
     dp[n] = (fib(n - 1, dp) % MOD + fib(n - 2, dp) % MOD) % MOD;
    return dp[n];
}

int countWays(int n)
{
    int dp[n + 1];
    memset(dp, -1, sizeof dp);
    fib(n, dp);
    return dp[n];
}
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends