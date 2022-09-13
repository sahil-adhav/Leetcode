class Solution {
public:
    
    int f(int day, int buy, int cap, int n, vector<int>& prices, vector<vector<vector<int>>> &dp){
        //Base Case
        if(cap == 0) return 0;
        if(day == n) return 0;
        
        if(dp[day][buy][cap] != -1) return dp[day][buy][cap]; 
        //Calculation
        int profit = INT_MIN;
        if(buy){
            profit = max(-prices[day] + f(day+1, 0, cap, n, prices, dp), 
                         0 + f(day+1, 1, cap, n, prices, dp));
        }
        else{
            profit = max(prices[day] + f(day+1, 1, cap-1, n, prices, dp), 
                        0 + f(day+1, 0, cap, n, prices, dp));
        }
        return dp[day][buy][cap] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, n, prices, dp);
    }
};