class Solution {
public:
    
//     int help(int m, int n, vector<vector<int>> &dp){
//         if(m == 0 and n == 0){
//             return 1;
//         }
        
//         if(m < 0 or n < 0){
//             return 0;
//         }
        
//         if(dp[m][n] != -1){
//             return dp[m][n];
//         }
        
//         int up = help(m-1, n, dp);
//         int left = help(m, n-1, dp);
        
//         return dp[m][n] = up + left;    
//     }
    
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        int dp[m][n];
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 and j == 0) dp[i][j] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i > 0){
                        up = dp[i-1][j];
                    }
                    if(j > 0){
                        left = dp[i][j-1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};