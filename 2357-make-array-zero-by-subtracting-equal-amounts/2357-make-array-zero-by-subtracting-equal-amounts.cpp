class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         priority_queue<int, vector<int>, greater<int>> pq;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) pq.push(nums[i]);
    }
    int ans = 0;
    int sum = 0;
    while (!pq.empty()) {
      if (pq.top() > sum) {
        sum = pq.top();
        pq.pop();
        ans++;
      } else
        pq.pop();
    }
    return ans;
    }
};