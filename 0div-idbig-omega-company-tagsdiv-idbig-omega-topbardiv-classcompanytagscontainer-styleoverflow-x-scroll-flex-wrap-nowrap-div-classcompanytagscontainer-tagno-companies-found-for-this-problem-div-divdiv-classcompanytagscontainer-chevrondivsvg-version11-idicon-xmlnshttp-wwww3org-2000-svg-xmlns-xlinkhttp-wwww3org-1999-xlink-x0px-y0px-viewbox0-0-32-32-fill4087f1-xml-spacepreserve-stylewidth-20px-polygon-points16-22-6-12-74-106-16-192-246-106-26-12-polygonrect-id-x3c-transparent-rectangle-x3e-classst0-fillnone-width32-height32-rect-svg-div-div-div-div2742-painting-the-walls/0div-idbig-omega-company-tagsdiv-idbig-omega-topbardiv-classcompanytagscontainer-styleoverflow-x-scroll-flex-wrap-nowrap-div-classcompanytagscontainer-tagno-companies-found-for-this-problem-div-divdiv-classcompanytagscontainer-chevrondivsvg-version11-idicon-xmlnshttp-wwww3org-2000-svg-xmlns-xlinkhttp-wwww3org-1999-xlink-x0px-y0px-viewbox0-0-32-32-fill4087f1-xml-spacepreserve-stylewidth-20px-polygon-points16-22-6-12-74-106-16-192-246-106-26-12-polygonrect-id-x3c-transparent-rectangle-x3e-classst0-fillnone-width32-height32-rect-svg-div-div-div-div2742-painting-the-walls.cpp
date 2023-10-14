class Solution {
public:
     int dp[501][501];
     
    long long find(int i,int topaint,vector<int>&cost,vector<int>&time){
        if(topaint<=0)return 0;
        if(dp[i][topaint]  != -1)return dp[i][topaint];

        if(i == 0){
            long long cur = topaint - (time[i]+1);
            if(cur>0)return dp[i][topaint]= INT_MAX;
            else return dp[i][topaint] = cost[i];
        }
        else{
    
            long long cur = cost[i] + find(i-1,(topaint-(time[i]+1)),cost,time);
            cur = min(cur,find(i-1,topaint,cost,time));
            return dp[i][topaint] = cur;
        }
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        int n = cost.size();
        return find(n-1,n,cost,time);
    }
  
};