class Solution {
public:
    
    int f(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
        //Base Case
        if(ind == 0){
            if(amount % coins[ind] == 0){
                return amount/coins[ind];
            }
            else{
                return 1e9;
            }
        }
        
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }
        
        //Calculation
        int notPick = 0 + f(ind-1, amount, coins, dp);
        int pick = INT_MAX;
        if(coins[ind] <= amount){
            pick = 1 + f(ind, amount-coins[ind], coins, dp);
        }
        return dp[ind][amount] = min(pick, notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = f(n-1, amount, coins, dp);
        return (ans == 1e9) ? -1 : ans;
    }
};