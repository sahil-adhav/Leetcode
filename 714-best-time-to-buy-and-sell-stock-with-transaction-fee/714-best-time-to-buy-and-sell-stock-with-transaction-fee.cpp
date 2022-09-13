class Solution {
public:
    
    int f(int day, int buy, int fee, int n, vector<int>& prices, vector<vector<int>> &dp){
        if(day == n) return 0;
        if(dp[day][buy] != -1) return dp[day][buy];
        
        int maxProfit = INT_MIN;
        if(buy==1){
            maxProfit = max(-prices[day]+f(day+1, 0, fee, n, prices, dp), 
                           0+f(day+1, 1, fee, n, prices, dp));
        }
        else{
            maxProfit = max((prices[day]-fee)+f(day+1, 1, fee, n, prices, dp),
                           0+f(day+1, 0, fee, n, prices, dp));
        }
        return dp[day][buy] = maxProfit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int day=n-1; day>=0; day--){
            
            dp[day][1] = max(-prices[day]+dp[day+1][0], 
                           0+dp[day+1][1]);
            
            dp[day][0] = max(prices[day]-fee+dp[day+1][1],
                               0+dp[day+1][0]);
        }
        return dp[0][1];
    }
};