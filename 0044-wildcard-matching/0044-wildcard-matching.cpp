
class Solution {
public:
	bool f(int i,int j,string& p,string& s,vector<vector<int>>& dp){
		if(i==0 && j==0) return true;
		if(i==0 && j>0) return false;
		if(j==0 && i>0){
			for(int k=i;k>=1;k--){
				if(p[k-1]!='*') return false;
			}
			return true;
		}
		if(dp[i][j]!=-1) return dp[i][j];
//      Match 
		if(p[i-1]==s[j-1] || p[i-1]=='?') return dp[i][j]=f(i-1,j-1,p,s,dp);
		if(p[i-1]=='*') return dp[i][j]=f(i-1,j,p,s,dp) || f(i,j-1,p,s,dp);
//      NotMatch
		return dp[i][j]=false;
	}

	bool isMatch(string s, string p) {
		int n=p.size();
		int m=s.size();
		vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
		return f(n,m,p,s,dp);
	}
};