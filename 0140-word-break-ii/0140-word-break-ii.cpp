class Solution {
public:
    void help(int i, string &str, set<string>& words, string temp, vector<string>&ans){
        if(i==str.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        string s = "";

        for(int j=i; j<str.size(); j++){
            s += str[j];
            if(words.find(s) != words.end()){
                s += ' ';
                help(j+1,str,words,temp+s,ans);
                s.pop_back();
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto a: wordDict){
            st.insert(a);
        }
         vector<string> ans;
        help(0,s, st,"",ans);
        return ans;
    }
};