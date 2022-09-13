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
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        // for(int ind=0; ind<=n; ind++){
        //     for(int buy=0; buy<=1; buy++){
        //         dp[ind][buy][0] = 0;
        //     }
        // }
        
        for(int day=n-1; day>=0; day--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy==1){
                        dp[day][buy][cap] = max(-prices[day] + dp[day+1][0][cap], 
                                     0 + dp[day+1][1][cap]);
                    }
                    else{
                        dp[day][buy][cap] = max(prices[day] + dp[day+1][1][cap-1], 
                                    0 + dp[day+1][0][cap]);
                    }
                    // dp[day][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};