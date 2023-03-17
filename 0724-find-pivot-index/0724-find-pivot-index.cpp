class Solution {
public:
    int pivotIndex(vector<int>& nums) {
               int sum = 0, leftsum = 0;
        for (int j=0; j <nums.size(); ++j ) sum += nums[j];
        for (int i = 0; i <nums.size(); ++i) {
            if (leftsum == sum - leftsum - nums[i]) return i;
            leftsum += nums[i];
        }
        return -1;
    }
};