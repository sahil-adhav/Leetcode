class Solution {
public:
    
    int lcs_help(string &s, string&t){
        int n = s.length();
        int m = t.length();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        //Base Condition
        for(int j=0; j<=m; j++){
            prev[j] = 0;
        }
        
        //calculations
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
    
    int lcs(string &s){
        string t = s;
        reverse(t.begin(), t.end());
        return lcs_help(s, t);
    }
    
    int minInsertions(string s) {
        int len = s.length();
        return len - lcs(s);
    }
};