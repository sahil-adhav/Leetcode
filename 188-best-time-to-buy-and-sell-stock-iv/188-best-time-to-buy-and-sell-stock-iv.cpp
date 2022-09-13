class Solution {
public:
    
    int f(int day, int buy, int cap, int n, vector<int>& prices, vector<vector<vector<int>>> &dp){
        //Base cases
        if(cap == 0) return 0;
        if(day == n) return 0;
        if(dp[day][buy][cap] != -1) return dp[day][buy][cap];
        
        //Calculation
        int maxProfit = INT_MIN;
        if(buy == 1){
            maxProfit = max(-prices[day] + f(day+1, 0, cap, n, prices, dp), 
                        0 + f(day+1, 1, cap, n, prices, dp));
        }
        else{
            maxProfit = max(prices[day] + f(day+1, 1, cap-1, n, prices, dp), 
                        0 + f(day+1, 0, cap, n, prices, dp));    
        }
        
        return dp[day][buy][cap] = maxProfit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //days ---- buy/sell ---- cap
        // days x 2 x k
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0,1,k,n,prices, dp);
    }
};