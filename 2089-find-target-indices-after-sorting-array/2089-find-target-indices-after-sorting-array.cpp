//linear search
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
       int s=0, e= nums.size()-1;
        int res1=-1;
        //1st occurence
        while(s<=e){
            int mid= s+(e-s)/2;
            if(target==nums[mid])
            {
                res1= mid;
                e= mid-1;
            }
            else if(target<nums[mid])
                e=mid-1;
            else 
                s=mid+1;
        }
        //2nd occurence
         s=0;
        e= nums.size()-1;
        int res2=-1;
         while(s<=e){
             int mid= s+(e-s)/2;
            if(target==nums[mid])
            {
                res2= mid;
                s= mid+1;
            }
            else if(target<nums[mid])
                e=mid-1;
            else 
                s=mid+1;
        }
        for(int i=res1; i<=res2; i++){
            if(i!=-1)
                ans.push_back(i);
        }
        return ans;
    }
};