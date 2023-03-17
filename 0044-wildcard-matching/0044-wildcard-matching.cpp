
class Solution {
public:
	bool f(int i,int j,string& p,string& s,vector<vector<int>>& dp){
		if(i<0 && j<0) return true;
		if(i<0 && j>=0) return false;
		if(j<0 && i>=0){
			for(int k=i;k>=0;k--){
				if(p[k]!='*') return false;
			}
			return true;
		}
		if(dp[i][j]!=-1) return dp[i][j];
//      Match 
		if(p[i]==s[j] || p[i]=='?') return dp[i][j]=f(i-1,j-1,p,s,dp);
		if(p[i]=='*') return dp[i][j]=f(i-1,j,p,s,dp) || f(i,j-1,p,s,dp);
//      NotMatch
		return dp[i][j]=false;
	}

	bool isMatch(string s, string p) {
		int n=p.size();
		int m=s.size();
		vector<vector<int>> dp(n,vector<int>(m,-1));
		return f(n-1,m-1,p,s,dp);
	}
};