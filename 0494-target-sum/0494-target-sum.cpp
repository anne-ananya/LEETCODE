class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    int n, total=0,sum=0;
    n= nums.size();
    for(int i=0; i<n; i++)
    total+= nums[i];

if(abs(target) > total ||(total+target)%2!=0)return 0;
sum= (total+target)/2;
int t[n+1][sum+1];
for(int i=0; i<n+1; i++){
    for(int j=0; j<sum+1;j++){
       t[0][j]=0;
    }
}

t[0][0]=1;

for(int i=1; i<n+1; i++){
    for(int j=0; j<sum+1;j++){
       if(nums[i-1]<=j) t[i][j]= t[i-1][j-nums[i-1]]+ t[i-1][j];
       else t[i][j]= t[i-1][j];
    }
}

return t[n][sum];
    }
};