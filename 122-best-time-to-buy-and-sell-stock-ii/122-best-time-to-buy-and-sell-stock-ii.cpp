class Solution {
public:
    
        
    int f(int ind, int buy, vector<int>& prices, int n, vector<vector<int>> &dp){
        // base case
        if(ind == n){
            return 0;
        }        
        
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        
        // calculation
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(ind+1, 0, prices, n, dp), 0 + f(ind+1, 1, prices, n, dp));
        }
        else{
            profit = max(prices[ind] + f(ind+1, 1, prices, n, dp), 0 + f(ind+1, 0, prices, n, dp));
        }
        
        return dp[ind][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int ind=n-1; ind>=0; ind--){
            dp[ind][1] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            dp[ind][0] = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
        }
        return dp[0][1];
    }
};


    
    
    