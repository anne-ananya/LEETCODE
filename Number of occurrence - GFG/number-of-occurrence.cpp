//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int x) {
	            vector<int>ans;
       int s=0, e= n-1;
        int res1=-1;
        //1st occurence
        while(s<=e){
            int mid= s+(e-s)/2;
            if(x==nums[mid])
            {
                res1= mid;
                e= mid-1;
            }
            else if(x<nums[mid])
                e=mid-1;
            else 
                s=mid+1;
        }
        //2nd occurence
         s=0;
        e= n-1;
        int res2=-1;
         while(s<=e){
             int mid= s+(e-s)/2;
            if(x==nums[mid])
            {
                res2= mid;
                s= mid+1;
            }
            else if(x<nums[mid])
                e=mid-1;
            else 
                s=mid+1;
        }
        for(int i=res1; i<=res2; i++){
            if(i!=-1)
                ans.push_back(i);
        }
        return ans.size();
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends