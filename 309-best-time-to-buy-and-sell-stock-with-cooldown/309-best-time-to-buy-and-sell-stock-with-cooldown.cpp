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
        vector<int>f1(2, 0), f2(2,0), curr(2,0);
        
        for(int day=n-1; day>=0; day--){
            curr[1] = max(-prices[day]+f1[0],
                           0+f1[1]);
            curr[0] = max(prices[day]+f2[1],
                           0+f1[0]); 
            
            f2=f1;
            f1=curr;
        }
        return curr[1];
    }
};