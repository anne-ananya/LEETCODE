class Solution {
public:
    int partitionString(string s) {
        unordered_set <char> st;
        int parts=0;
        for(int i=0; i<s.size(); i++){
            if(st.find(s[i])!= st.end()){
                parts++;
                st.clear();
            }
            st.insert(s[i]);
        }
        return parts+1;
    }
};