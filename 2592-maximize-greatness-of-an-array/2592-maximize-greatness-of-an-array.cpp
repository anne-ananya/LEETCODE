class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
       int l = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        int i=0;
        for(int j=1; j<l; j++){
            if(nums[i]<nums[j]){
                ans++;
                i++;
            }
        }
        return ans;
    }
};