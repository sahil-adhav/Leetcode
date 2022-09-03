class Solution {
public:
    

int f(int ind, vector<int>& a, int T, vector<vector<int>> &dp){
    if(ind == 0){
        return (T % a[0] == 0);
    }
    
    if(dp[ind][T] != -1){
        return dp[ind][T];
    }
    
    int notPick = f(ind-1, a, T, dp);
    int pick = 0;
    if(a[ind] <= T){
        pick = f(ind, a, T-a[ind], dp);
    }
    
    return dp[ind][T] = pick + notPick;
}
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
        for(int T=0; T<=amount; T++){
            dp[0][T] = (T % coins[0] == 0);
        }
        
        for(int ind=1; ind<n; ind++){
            for(int T=0; T<=amount; T++){
                int notPick = dp[ind-1][T];
                int pick = 0;
                if(coins[ind] <= T){
                    pick = dp[ind][T-coins[ind]];
                }
                dp[ind][T] = pick + notPick;
            }
        }
        
        return dp[n-1][amount];
    }
};