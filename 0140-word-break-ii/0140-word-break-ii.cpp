class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        unordered_map<int, vector<string>> memo;
        return wordBreakMemo(s, 0, wordSet, memo);
    }

    vector<string> wordBreakMemo(const string& s, int start, const unordered_set<string>& wordSet, unordered_map<int, vector<string>>& memo) {
        if (memo.count(start))
            return memo[start];

        vector<string> result;
        if (start == s.length()) {
            result.push_back("");
            return result;
        }

        for (int end = start + 1; end <= s.length(); ++end) {
            string word = s.substr(start, end - start);

            if (wordSet.count(word)) {
                vector<string> wordBreaks = wordBreakMemo(s, end, wordSet, memo);
                for (const string& wb : wordBreaks) {
                    result.push_back(word + (wb.empty() ? "" : " ") + wb);
                }
            }
        }
        memo[start] = result;
        return result;
    }
};
