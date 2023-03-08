//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n, vector<int>(n+1, 0));
        for(int j=0; j<=n; j++){
            dp[0][j]=  j*price[0];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=n; j++){
            int nottake = 0+ dp[i-1][j];
      int take = -1e8;
      int rod= i+1;
      if(rod<=j)
      take = price[i]+ dp[i][j-rod];
      dp[i][j]= max(take, nottake);
        }
        }
      return dp[n-1][n];  
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends