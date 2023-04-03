class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        string ans;
        while(!pq.empty()){
            int f=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            for(int i=0;i<f;i++)
                ans+=ch;          
                
        }
        return ans;
    }
};