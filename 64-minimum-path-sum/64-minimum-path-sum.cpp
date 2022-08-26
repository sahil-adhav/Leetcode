class Solution {
public:
    
//     int f(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
//         if(i == 0 and j == 0){
//             return grid[i][j];
//         }
        
//         if(i < 0 or j < 0){
//             return 1e9;
//         }
        
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
        
//         int left = grid[i][j] + f(grid, dp, i, j-1);
//         int up = grid[i][j] + f(grid, dp, i-1, j);
        
//         return dp[i][j] = min(left, up);
//     }
    
    int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));
        
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(i==0 and j==0){
//                     dp[i][j] = grid[i][j];
//                 }
//                 else{
//                     int left = grid[i][j];
//                     int up = grid[i][j];
                    
//                     if(j > 0){
//                         left += dp[i][j-1];
//                     }
//                     else{
//                         left += 1e9;
//                     }
                    
//                     if(i > 0){
//                         up += dp[i-1][j];
//                     }
//                     else{
//                         up += 1e9;
//                     }
//                     dp[i][j] = min(left, up);
//                 }
//             }
//         }
//         return dp[m-1][n-1];

        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        
        for(int i=0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                if(i==0 and j==0){
                    curr[j] = grid[i][j];
                }
                else{
                    int left = grid[i][j];
                    int up = grid[i][j];
                    
                    if(j > 0){
                        left += curr[j-1];
                    }
                    else{
                        left += 1e9;
                    }
                    
                    if(i > 0){
                        up += prev[j];
                    }
                    else{
                        up += 1e9;
                    }
                    curr[j] = min(left, up);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};