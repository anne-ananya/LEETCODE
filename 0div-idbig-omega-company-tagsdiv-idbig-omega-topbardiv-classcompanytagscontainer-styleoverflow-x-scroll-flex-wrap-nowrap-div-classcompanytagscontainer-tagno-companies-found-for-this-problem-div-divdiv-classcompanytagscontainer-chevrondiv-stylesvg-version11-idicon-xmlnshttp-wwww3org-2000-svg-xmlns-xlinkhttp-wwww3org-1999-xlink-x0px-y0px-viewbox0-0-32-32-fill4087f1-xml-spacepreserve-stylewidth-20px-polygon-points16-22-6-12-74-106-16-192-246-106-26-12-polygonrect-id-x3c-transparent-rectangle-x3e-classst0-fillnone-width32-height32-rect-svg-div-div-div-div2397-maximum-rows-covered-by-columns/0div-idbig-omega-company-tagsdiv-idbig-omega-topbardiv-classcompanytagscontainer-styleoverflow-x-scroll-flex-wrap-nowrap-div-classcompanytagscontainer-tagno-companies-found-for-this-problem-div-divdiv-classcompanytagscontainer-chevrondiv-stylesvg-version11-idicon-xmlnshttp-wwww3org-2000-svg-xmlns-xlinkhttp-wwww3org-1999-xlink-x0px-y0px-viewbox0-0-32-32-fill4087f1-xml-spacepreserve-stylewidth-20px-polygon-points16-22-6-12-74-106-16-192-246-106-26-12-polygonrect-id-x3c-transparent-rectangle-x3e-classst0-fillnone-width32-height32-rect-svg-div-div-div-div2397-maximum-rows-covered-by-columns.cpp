class Solution {
public:
    void picknotpick(vector<vector<int>>& matrix, int numSelect, int ind, int curSelect, vector<bool>& vis, int &ans) {
        bool flag = true;
        if (ind == matrix[0].size()) {
            int cnt = 0;
            for (int i = 0; i < matrix.size(); i++) {
                flag = true; 
                for (int j = 0; j < matrix[0].size(); j++) {
                    if (matrix[i][j] == 1) {
                        if (vis[j] == false) {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
            return;
        }
      
        if (curSelect < numSelect) {
            vis[ind] = true;
            picknotpick(matrix, numSelect, ind + 1, curSelect + 1, vis, ans);
            vis[ind] = false;
        }
            picknotpick(matrix, numSelect, ind + 1, curSelect, vis, ans); 
        
    }

    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int curSelect = 0;
        vector<bool> vis(matrix[0].size(), false);
        int ans = 0;
        picknotpick(matrix, numSelect, 0, 0, vis, ans);
        return ans; 
    }
};
