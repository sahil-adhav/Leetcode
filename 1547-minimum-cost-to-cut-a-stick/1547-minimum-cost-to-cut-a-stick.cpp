class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return f(1, c, cuts, dp);
    }
    
    int f(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        if(i > j) return 0;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int mini = 1e9;
        
        for(int k=i; k<=j; k++){
            int minCost_ = (cuts[j+1] - cuts[i-1]) + f(i, k-1, cuts, dp) + f(k+1, j, cuts, dp);
            mini = min(mini, minCost_);
        }
        return dp[i][j] = mini;
    }
};