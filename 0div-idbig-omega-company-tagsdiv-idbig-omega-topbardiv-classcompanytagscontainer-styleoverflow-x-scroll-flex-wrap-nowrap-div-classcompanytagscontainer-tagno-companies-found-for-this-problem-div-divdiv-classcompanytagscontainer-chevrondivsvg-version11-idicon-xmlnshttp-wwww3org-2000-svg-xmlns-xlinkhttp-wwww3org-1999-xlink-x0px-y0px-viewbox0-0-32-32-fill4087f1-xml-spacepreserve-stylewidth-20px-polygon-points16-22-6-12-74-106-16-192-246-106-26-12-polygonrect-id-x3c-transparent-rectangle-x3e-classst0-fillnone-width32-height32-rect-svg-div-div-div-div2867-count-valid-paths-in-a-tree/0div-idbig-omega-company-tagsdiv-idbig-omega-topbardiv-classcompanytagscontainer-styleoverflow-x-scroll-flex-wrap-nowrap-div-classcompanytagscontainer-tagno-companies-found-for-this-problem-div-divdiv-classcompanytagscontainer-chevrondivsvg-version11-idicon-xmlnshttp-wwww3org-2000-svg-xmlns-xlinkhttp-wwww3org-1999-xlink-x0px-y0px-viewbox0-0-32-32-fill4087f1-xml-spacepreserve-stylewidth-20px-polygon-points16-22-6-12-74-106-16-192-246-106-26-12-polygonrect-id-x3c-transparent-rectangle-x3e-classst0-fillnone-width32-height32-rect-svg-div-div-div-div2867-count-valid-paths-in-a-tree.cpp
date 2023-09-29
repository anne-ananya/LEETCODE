#define ll long long
const int N = 1e5 + 5 ; 

class Solution {
public:
    bool isprime[N+1] ;
    void init(){
        memset(isprime , 1 , sizeof(isprime)) ;
        isprime[1] = 0 ; 
        for(int i = 2 ; i * i <= N ; ++i ){
            for(int j = i * i ; j <= N ; j += i ){
                isprime[j] = 0 ; 
            }
        }
    }


    vector<vector<int>> adj ;
    ll dp[N][2] ;
    vector<bool> vis ;
    
    void dfs(int src ){
        vis[src] = 1 ;
        ll zero = 0 , one = 0 ;
        for(auto it : adj[src] ){
            if(!vis[it]){
                dfs(it) ;
                zero += dp[it][0] ;
                one += dp[it][1] ;
            }
        }
        if(isprime[src+1] ){
            dp[src][0] = 0 ;
            dp[src][1] = zero + (ll)1 ;
        }
        else{
            dp[src][0] = zero + (ll)1 ;
            dp[src][1] = one ;
        }
        vis[src] = 0 ; 
    }

    ll ans[N] ;
    void dfs2(int src ){

        vis[src] = 1 ;
        ll zero = 0 , one = 0 ;
        ans[src] = dp[src][1] ;
        if(isprime[src+1] ) --ans[src] ;

        for(auto it : adj[src] ){
            if(!vis[it]){
                dfs2(it ) ;
                zero += dp[it][0] ;
                one += dp[it][1] ;
                ans[src] += ans[it] ;
            }
        }
        ll cnt = 0 ; 
        for(auto it : adj[src] ){
            if(!vis[it]){
                if( !isprime[src+1] ){
                    cnt += (one - dp[it][1])*dp[it][0]  ;
                    cnt += (zero - dp[it][0])*dp[it][1] ;
                }
                else{
                    cnt += (zero - dp[it][0])*dp[it][0] ;
                }
            }
        }
        cnt = cnt / 2 ;
        ans[src] += cnt ;
        
        vis[src] = 0 ;
    }

    long long countPaths(int n, vector<vector<int>>& edges) {
        init() ;

        adj.clear() ;
        adj.resize(n) ;
        for(auto it : edges ){
            adj[it[0]-1].push_back(it[1]-1) ;
            adj[it[1]-1].push_back(it[0]-1) ;
        }
        memset(dp , 0 , sizeof(dp)) ;

        vis.clear() ;
        vis.resize(n, 0 ) ;
        
        dfs(0) ;
        memset(ans , 0 , sizeof(ans)) ;
        dfs2(0) ;
        ll cnt = ans[0] ;
        return cnt ;
    }
};


