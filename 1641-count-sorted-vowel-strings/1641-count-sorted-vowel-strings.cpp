class Solution {
public:
    int f(int index, string &s,int n){
        if(n==0) return 1;
   		if(index>=5) return 0;
   		int pick, notPick;
   		pick= f(index, s, n-1);
   		notPick= f(index+1, s, n);
        return pick + notPick;
    }
    int countVowelStrings(int n) {
        string s= "aeiou";
        return f(0, s, n);
        
    }
};

 