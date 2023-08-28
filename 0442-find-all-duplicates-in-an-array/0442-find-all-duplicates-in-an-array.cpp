class Solution {
    //O(N) 0(1)
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
      
        for (int num : nums) {
            if (nums[std::abs(num) - 1] < 0) {
                ans.push_back(abs(num));
            } else {
                nums[abs(num) - 1] = -nums[abs(num) - 1];
            }
        }

        return ans;
    }
};