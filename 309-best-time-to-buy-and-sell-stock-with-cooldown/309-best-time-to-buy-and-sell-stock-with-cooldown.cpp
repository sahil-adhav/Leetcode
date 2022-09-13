class Solution {
public:
    
    int f(int day, int buy, int n, vector<int> &prices, vector<vector<int>> &dp){
        if(day >= n) return 0;
        if(dp[day][buy] != -1) return dp[day][buy];
        int maxProfit = INT_MIN;
        
        if(buy==1){
            maxProfit = max(-prices[day]+f(day+1, 0, n, prices, dp),
                           0+f(day+1, 1, n, prices, dp));
        }
        else{
            maxProfit = max(prices[day]+f(day+2, 1, n, prices, dp),
                           0+f(day+1, 0, n, prices, dp));    
        }
        return dp[day][buy] = maxProfit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return f(0,1,n,prices,dp);
    }
};