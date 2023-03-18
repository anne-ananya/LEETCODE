//space optimized
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<vector<int>>after(2, vector<int>(3,0));
        vector<vector<int>>cur(2, vector<int>(3,0));
        for(int i=n-1; i>=0; i--){
           for(int buy=0; buy<=1; buy++){
               for(int cap=1; cap<=2; cap++){ 
           if(buy==1){
            cur[buy][cap] = max(after[0][cap]-prices[i], after[1][cap]);
        }
          else{
             cur[buy][cap] = max(after[1][cap-1]+prices[i], after[0][cap] ); 
          }
        }
        }
            after=cur;
        }
        return after[1][2];
    }
};