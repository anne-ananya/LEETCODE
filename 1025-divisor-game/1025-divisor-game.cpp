class Solution {
public:
    bool divisorGame(int n) {
        if(n==0)
            return true;
        for(int x=1; x<n; x++){
            if(n%x==0)
                return !divisorGame(n-x);
        }
        return false;
    }
};