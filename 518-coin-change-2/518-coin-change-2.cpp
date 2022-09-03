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
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return f(n-1, coins, amount, dp);
    }
};