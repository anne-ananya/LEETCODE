class Solution {
public:
    
int minFallingPathSum(vector<vector<int> > &matrix){
    
     int n = matrix.size();
    
    vector<int> prev(n,0), cur(n,0);
    
    // Initializing first row - base condition
    for(int j=0; j<n; j++){
        prev[j] = matrix[0][j];
    }
    
      for(int i = 1; i < n; ++i){
            for(int j = 0; j < n; ++j){

                cur[j] = INT_MAX;

                for(int k = 0; k < n; ++k){
                    if(j == k)
                        continue;
                    cur[j] = min(prev[k] + matrix[i][j],cur[j]);
                }
            }
            prev = cur;
        }
    
    int mini = INT_MAX;
    
    for(int j=0; j<n;j++){
        mini = min(mini,prev[j]);
    }
    
    return mini;

}
};


