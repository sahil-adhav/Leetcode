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
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        
        for(int T=0; T<=amount; T++){
            prev[T] = (T % coins[0] == 0);
        }
        
        for(int ind=1; ind<n; ind++){
            for(int T=0; T<=amount; T++){
                int notPick = prev[T];
                int pick = 0;
                if(coins[ind] <= T){
                    pick = curr[T-coins[ind]];
                }
                curr[T] = pick + notPick;
            }
            prev = curr;
        }
        
        return prev[amount];
    }
};