class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
 
    for (int i = 0; i < arr.size(); i++)
        mp[arr[i]]++;
       priority_queue<int> pq;
        for (auto it : mp) {
            pq.push(it.second);
        }
        int removed = 0, count = 0;
        while (!pq.empty() && count < arr.size() / 2) {
            count += pq.top();
            pq.pop();
            removed++;
        }
        return removed;
    }
};