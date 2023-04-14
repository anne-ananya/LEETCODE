//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack <int> st1;
        stack <int> st2;
        int t=-1, r=-1;
        for(int i=0; i<N; i++){
            if(st1.empty() && st2.empty()){
            st1.push(color[i]);
            st2.push(radius[i]);
            }
            else{
             r= st2.top();
            t= st1.top();
            if(t== color[i] && r==radius[i] ){
                st1.pop();
                st2.pop();
            }
            else{
             st1.push(color[i]);
            st2.push(radius[i]);   
            }
            }
        }
        return st1.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends