class Solution {
public:
    
    int f(string s, string t, int i, int j, vector<vector<int>> &dp){
        //Base Case
        if(j == 0) return 1;
        if(i == 0) return 0;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        //Calculation
        if(s[i-1] == t[j-1]){
            return dp[i][j] = f(s, t, i-1, j-1, dp) + f(s, t, i-1, j, dp);
        }
        return dp[i][j] = f(s, t, i-1, j, dp);
    }
    
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<double> prev(m+1, 0);
        
        prev[0]  = 1;
        
        //calculation
        for(int i=1; i<=n; i++){
            for(int j=m; j>=1; j--){
                if(s[i-1] == t[j-1]){
                    prev[j] = prev[j-1] + prev[j];
                }
                else{
                    prev[j] = prev[j];
                }
            }
            // prev = curr;
        }
        return (int)prev[m];
    }
};