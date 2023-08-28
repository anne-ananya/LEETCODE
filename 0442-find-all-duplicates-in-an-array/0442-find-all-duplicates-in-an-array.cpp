class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       int l=0, r=1;
        sort(nums.begin(), nums.end());
        vector<int>ans;
        while(l<r && r<nums.size()){
            if(nums[l]==nums[r])
            {
                ans.push_back(nums[l]);
                l++;
                r++;
            }
            l++;
            r++;
        }
        return ans;
    }
};