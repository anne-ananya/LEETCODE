class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
         sort(potions.begin(), potions.end());
        vector<int> answer;
        
        int m = potions.size();
        int maxPotion = potions[m - 1];
        
        for (auto& spell : spells) {
            long long minPotion = ceil((1.0 * success) / spell);
            if (minPotion > maxPotion) {
                answer.push_back(0);
                continue;
            }
            auto index = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();
            answer.push_back(m - index);
        }
        
        return answer;
    }
};