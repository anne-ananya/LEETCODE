class Solution {
public:
    int dfs(unordered_map<int, vector<int>>adj, vector<vector<int>>& richer, vector<int>& quiet, vector<int>&ans, int node){
        int x= node;
        for(auto it: adj[node]){
            if(ans[it]!=-1){
                if(quiet[ans[it]]<quiet[x])
                    x=ans[it];
            }
            else{
                int y= dfs(adj, richer, quiet, ans, it);
                    if(quiet[x]>quiet[y])
                        x=y;
            }
        }
        return ans[node]=x;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n= quiet.size();
        unordered_map<int, vector<int>>adj;
        vector<int>ans(n, -1);
        for(int i=0; i<richer.size(); i++){
            adj[richer[i][1]].push_back(richer[i][0]);
        }
        for(int i=0; i<n; i++){
            if(ans[i]==-1)
                dfs(adj, richer, quiet, ans, i);
        }
        return ans;
    }
};