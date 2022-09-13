class Solution {
public:
    
    int f(int ind, int prev, int n, vector<int> &nums, vector<vector<int>> &dp){
        if(ind == n) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int notPick = f(ind+1, prev, n, nums, dp);
        int pick = -1e9;
        if(prev == -1 or nums[ind] >  nums[prev]) pick = 1 + f(ind+1, ind, n, nums, dp);
        
        return dp[ind][prev+1] = max(pick, notPick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int ind=n-1; ind>=0; ind--){
            for(int prev = ind-1; prev>=-1; prev--){
                int notPick = dp[ind+1][prev+1];
                int pick = -1e9;
                if(prev == -1 or nums[ind] >  nums[prev]){ 
                    pick = 1 + dp[ind+1][ind+1];
                }

                dp[ind][prev+1] = max(pick, notPick);
            }
        }
        return dp[0][-1+1];
    }
};