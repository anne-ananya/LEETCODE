class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> ump(ideas.begin(), ideas.end());
        vector<vector<int>> cur(128, vector<int>(128,0));
        
        long long ans = 0;
        for (string& s : ideas) {
            for (char c='a'; c<='z'; c++){
                string word = s;
                word[0] = c;
                if (ump.find(word) == ump.end()){
                    ans += cur[s[0]][c];
                    cur[c][s[0]]++;
                }
            }
        }
        return ans * 2;
    }
};