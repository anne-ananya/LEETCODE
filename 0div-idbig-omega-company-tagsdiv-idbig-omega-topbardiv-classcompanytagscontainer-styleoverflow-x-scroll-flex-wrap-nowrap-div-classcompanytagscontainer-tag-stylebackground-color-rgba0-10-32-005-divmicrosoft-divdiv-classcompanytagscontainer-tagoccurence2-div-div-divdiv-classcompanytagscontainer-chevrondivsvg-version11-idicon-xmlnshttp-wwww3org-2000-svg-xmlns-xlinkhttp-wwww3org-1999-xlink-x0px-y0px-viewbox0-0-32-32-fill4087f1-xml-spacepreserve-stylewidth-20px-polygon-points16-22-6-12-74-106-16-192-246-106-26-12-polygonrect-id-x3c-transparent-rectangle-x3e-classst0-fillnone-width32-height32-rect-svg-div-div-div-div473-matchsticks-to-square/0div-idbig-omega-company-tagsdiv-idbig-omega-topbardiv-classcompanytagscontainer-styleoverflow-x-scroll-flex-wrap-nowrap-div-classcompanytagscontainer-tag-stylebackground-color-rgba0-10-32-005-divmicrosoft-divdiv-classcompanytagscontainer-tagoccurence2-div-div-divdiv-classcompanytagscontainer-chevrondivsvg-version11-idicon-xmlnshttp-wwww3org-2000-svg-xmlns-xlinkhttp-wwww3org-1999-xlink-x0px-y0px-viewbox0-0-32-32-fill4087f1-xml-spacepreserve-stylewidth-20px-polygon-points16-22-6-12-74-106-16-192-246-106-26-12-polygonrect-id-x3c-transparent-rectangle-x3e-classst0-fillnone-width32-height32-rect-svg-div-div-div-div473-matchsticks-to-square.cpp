class Solution {
public:
    //temp variable keeping track of current side
    //sides keeping track of no of sides formed correctly
    //sum keeping track of the target
    bool f(vector<int>& matchsticks, vector<bool>& vis, int temp, int sum, int sides, int index) {
        if (temp < 0) return false; //side cant be formed
        if (sides == 1) return true; //3 sides formed so true
        if (temp == 0) return f(matchsticks, vis, sum, sum, sides - 1, 0);
        for (int i = index; i < matchsticks.size(); i++) {
            if (vis[i]) continue; //if vis we are skipping
            vis[i] = true; 
            if (f(matchsticks, vis, temp - matchsticks[i], sum, sides, i + 1)) return true;
            vis[i] = false; //backtracking and marking as false.
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4)
            return false;
        int sum=0;
        vector<bool> vis(matchsticks.size(), false);
        for(int i=0; i<matchsticks.size(); i++){
            sum+= matchsticks[i];
        }
        if(sum%4!=0)
            return false;
         return f(matchsticks, vis, sum/ 4, sum/ 4, 4, 0);
    }
};