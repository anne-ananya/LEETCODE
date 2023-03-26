class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector <int> vec;
        unordered_map <int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
       priority_queue<pair<int,int>> pq;
        for(auto it:mp){
            pq.push({(-1)*it.second,it.first});
        }
        while(!pq.empty()){
            pair<int,int> p1=pq.top();
            pq.pop();
            int freq=p1.first;
            while(freq<0){
                vec.push_back(p1.second);
                freq++;
            }
        }
        return vec;
        
    }
};