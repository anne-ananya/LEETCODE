class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        int n=gifts.size();

       priority_queue<int>pq;
       for(int i=0;i<n;i++){
           pq.push(gifts[i]);
           ans+=gifts[i];
       }

       while(!pq.empty() && k--){
           int t=pq.top();
           pq.pop();
           ans-=t;
           int val=sqrt(t);
           pq.push(val);
           ans+=val;
       }
       return ans;
    }
};