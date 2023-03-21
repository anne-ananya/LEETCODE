class Solution{
    public:
int countVowelStrings(int n) {

		string vowels= "aeiou";
		vector<vector<int>> dp(5, vector<int>(n+1)); 
		for(int i=0; i<5; ++i) dp[i][0]= 1;
		for(int i=4; i>=0; --i){
		  for(int j=1; j<=n; ++j){
			int pick= 0, notPick= 0;
			pick= dp[i][j-1];
			if(i<4) notPick= dp[i+1][j];
			dp[i][j]= pick+notPick;
		  }
		}

		return dp[0][n]; 
	}
};
 