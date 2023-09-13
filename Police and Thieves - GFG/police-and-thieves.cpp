//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        
    int res = 0;
    vector<int> thi;
    vector<int> pol;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'P')
            pol.push_back(i);
        else if (arr[i] == 'T')
            thi.push_back(i);
    }
    int l = 0, r = 0;
    while (l < thi.size() && r < pol.size()) {
        if (abs(thi[l] - pol[r]) <= k) {
            l++;
            r++;
            res++;
        }
        else if (thi[l] < pol[r]) {
            l++;
        }
        else {
            r++;
        }
    }
    return res;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends