class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, n, dp);
    }
    
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
};


    
    
    