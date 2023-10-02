class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++) m[nums[i]]=i;

        int minIndex=nums.size();
        for (int i=1;i<=k;i++) minIndex = min(minIndex,m[i]);

        return nums.size()-minIndex;
    }
};