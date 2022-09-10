class Solution {
public:
    
    int f(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        
        if(i < 0) return j+1;
        if(j <  0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]){
            return dp[i][j] = f(s, t, i-1, j-1, dp);
        }
        
        return dp[i][j] = 1 + min(f(s, t, i-1, j, dp), min(f(s, t, i, j-1, dp), f(s, t, i-1, j-1, dp)));
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(word1, word2, n-1, m-1, dp);
    }
};