//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string text) {
    unordered_map<char, int> map;

        for (int i = 0; i < pat.length(); i++) {
            if (map.find(pat[i]) != map.end()) {
                int cur = map[pat[i]];
                map[pat[i]] = cur + 1;
            } else {
                map[pat[i]] = 1;
            }
        }

        int i = 0, j = 0, count = map.size(), ans = 0;

        while (j < text.length()) {
            if (map.find(text[j]) != map.end()) {
                int cur = map[text[j]];
                if (cur == 1) {
                    map[text[j]] = cur - 1;
                    count--;
                } else {
                    map[text[j]] = cur - 1;
                }
            }

            if (j - i + 1 == pat.length()) {
                if (count == 0) {
                    ans++;
                }

                if (map.find(text[i]) != map.end()) {
                    int cur = map[text[i]];
                    if (cur == 0) count++;
                    map[text[i]] = cur + 1;
                }

                i++;
            }

            j++;
        }

        return ans;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends