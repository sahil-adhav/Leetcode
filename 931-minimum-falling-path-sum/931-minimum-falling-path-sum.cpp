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
        vector<int> prev(c+1, 0), curr(c+1, 0);
        
        for(int j=0; j<c; j++) prev[j] = matrix[0][j];
        
        for(int i=1; i<r; i++){
            for(int j=0; j<c; j++){
                int up = matrix[i][j] + prev[j];
                int left = matrix[i][j];
                if(j-1 >= 0) left += prev[j-1];
                else left += 1e9;
                int right = matrix[i][j];
                if(j+1 < c) right += prev[j+1];
                else right += 1e9;
                curr[j] = min({up, left, right});
            }
            prev = curr;
        }
        
        
        int maxi = INT_MAX;
        int n = matrix.size();
        for(int j=0; j<matrix.size(); j++){
            maxi = min(maxi, prev[j]);
        }
        return maxi;
    }
};