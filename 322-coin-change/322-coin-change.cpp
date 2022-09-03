class Solution {
public:
    
//     int f(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
//         //Base Case
//         if(ind == 0){
//             if(amount % coins[ind] == 0){
//                 return amount/coins[ind];
//             }
//             else{
//                 return 1e9;
//             }
//         }
        
//         if(dp[ind][amount] != -1){
//             return dp[ind][amount];
//         }
        
//         //Calculation
//         int notPick = 0 + f(ind-1, amount, coins, dp);
//         int pick = 1e9;
//         if(coins[ind] <= amount){
//             pick = 1 + f(ind, amount-coins[ind], coins, dp);
//         }
//          return dp[ind][amount] = min(pick, notPick);
//     }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
        //Base Case
        for(int T=0; T<=amount; T++){
            if(T%coins[0] == 0){
                dp[0][T] = T/coins[0];
            }
            else dp[0][T] = 1e9;
        }
        
        for(int ind=1; ind<n; ind++){
            for(int tar=0; tar<=amount; tar++){
                int notPick = 0 + dp[ind-1][tar];
                int pick = 1e9;
                if(coins[ind] <= tar){
                    pick = 1 + dp[ind][tar-coins[ind]];
                }
                dp[ind][tar] = min(pick, notPick);
            }
        }
        int ans = dp[n-1][amount];
        return (ans == 1e9) ? -1 : ans;
    }
};