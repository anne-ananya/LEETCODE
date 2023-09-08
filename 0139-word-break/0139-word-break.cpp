class Solution {
public:
    int help(int i, string s, set<string>& wordDict, vector<int>&dp){
        if(i==s.size())
            return 1;
        string temp;
        if(dp[i]!=-1)
            return dp[i];
        for(int j=i; j<s.size(); j++){
            temp+= s[j];
            if(wordDict.find(temp)!=wordDict.end()){
                if (help(j+1, s, wordDict, dp))
                    return dp[i]=1;
                
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set <string> st;
        vector<int> dp(301, -1);
        for(auto a: wordDict){
            st.insert(a);
        }
        return help(0, s, st, dp);
        
    }
};