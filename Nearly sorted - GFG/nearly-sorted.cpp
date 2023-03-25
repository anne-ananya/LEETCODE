//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        // Your code here
      priority_queue<int,vector<int>,greater<int>>minh;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            minh.push(arr[i]);
            if(minh.size()>k)
            {
                ans.push_back(minh.top());
                minh.pop();
            }
        }
        while(minh.size()>0)
        {
            ans.push_back(minh.top());
            minh.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends