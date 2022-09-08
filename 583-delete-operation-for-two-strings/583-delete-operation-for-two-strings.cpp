class Solution {
public:
    
    int longestCommonSubsequence(string &s, string &t){
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return n + m - 2*longestCommonSubsequence(word1, word2);
    }
};


/*

deletion = n - lcs
         = 3 - 2
         = 1
         
Insertion = m - lcs
          = 3 - 2
          = 1

*/