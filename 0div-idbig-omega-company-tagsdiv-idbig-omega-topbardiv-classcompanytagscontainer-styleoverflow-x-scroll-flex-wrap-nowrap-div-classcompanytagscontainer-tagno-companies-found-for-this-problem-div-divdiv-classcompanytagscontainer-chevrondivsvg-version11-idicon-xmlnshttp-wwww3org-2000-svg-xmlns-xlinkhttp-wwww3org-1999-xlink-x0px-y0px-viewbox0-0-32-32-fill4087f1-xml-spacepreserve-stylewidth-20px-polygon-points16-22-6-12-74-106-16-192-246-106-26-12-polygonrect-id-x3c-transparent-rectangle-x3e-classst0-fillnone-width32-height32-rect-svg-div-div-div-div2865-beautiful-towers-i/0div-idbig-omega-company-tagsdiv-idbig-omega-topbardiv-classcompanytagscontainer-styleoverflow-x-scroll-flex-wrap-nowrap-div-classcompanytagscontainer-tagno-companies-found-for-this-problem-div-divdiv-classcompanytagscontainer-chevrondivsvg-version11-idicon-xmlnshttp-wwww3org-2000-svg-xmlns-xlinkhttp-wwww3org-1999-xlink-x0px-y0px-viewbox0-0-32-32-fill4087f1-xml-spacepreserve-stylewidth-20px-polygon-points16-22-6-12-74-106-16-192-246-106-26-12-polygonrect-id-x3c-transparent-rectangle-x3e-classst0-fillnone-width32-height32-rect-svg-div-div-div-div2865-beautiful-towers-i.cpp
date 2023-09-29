class Solution {
public:
        long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n=maxHeights.size();
        vector<int>prevsmall(n,-1);
        vector<int>nextsmall(n,n);
        vector<long long>leftsum(n,0);
        vector<long long>rightsum(n,0);
        leftsum[0]=maxHeights[0];
        stack<int>st;
        st.push(0);
        //Calculate prevSmall
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && maxHeights[st.top()]>=maxHeights[i])
                st.pop();
            if(!st.empty())
                prevsmall[i]=st.top();
            int prev=prevsmall[i];
            int count=i-prev;
            leftsum[i]+=(long long)count*maxHeights[i];
            if(prev!=-1)
                leftsum[i]+=leftsum[prev];
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        st.push(n-1);
        //Calculate nextsmall;
        rightsum[n-1]=maxHeights[n-1];
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && maxHeights[st.top()]>=maxHeights[i])
                st.pop();
            if(!st.empty())
                nextsmall[i]=st.top();
            int next=nextsmall[i];
            int count=next-i;
            rightsum[i]+=(long long)count*maxHeights[i];
            if(next!=n)
                rightsum[i]+=rightsum[next];
            st.push(i);
        }
        long long maxcount=0;
        for(int i=0;i<n;i++)
        {   
            cout<<leftsum[i]<<" "<<rightsum[i]<<endl;
            maxcount=max(maxcount,leftsum[i]+rightsum[i]-maxHeights[i]);
        }
        return maxcount;

    }
};
