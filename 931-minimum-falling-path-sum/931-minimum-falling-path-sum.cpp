class Solution {
public:
    
    int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &matrix){
        if(j < 0 || j >= matrix[0].size()){
            return 1e9;
        }
        
        if(i == 0) return matrix[0][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = matrix[i][j] + f(i-1, j, dp, matrix);
        int left = matrix[i][j] + f(i-1, j-1, dp, matrix);
        int right = matrix[i][j] + f(i-1, j+1, dp, matrix);
        
        return dp[i][j] = min({up, left, right});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> dp(r+1, vector<int>(c+1, -1));
        int maxi = INT_MAX;
        int n = matrix.size();
        for(int i=0; i<matrix.size(); i++){
            maxi = min(maxi, f(n-1, i, dp, matrix));
        }
        return maxi;
    }
};