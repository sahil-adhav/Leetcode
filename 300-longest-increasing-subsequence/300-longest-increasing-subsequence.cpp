class Solution {
public:
    
    int f(int ind, int prev, vector<vector<int>> &dp, int n, vector<int> &nums){
        if(ind == n) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        
        int notPick = f(ind+1, prev, dp, n, nums);
        int pick = -1e9;
        if(prev == -1 or nums[ind] > nums[prev]) pick = 1 + f(ind+1, ind, dp, n, nums);
        
        return dp[ind][prev+1] = max(pick, notPick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=n-1; i>=0; i--){
            for(int prev=i-1; prev>=-1; prev--){
                int notPick = dp[i+1][prev+1];
                int pick = -1e9;
                if(prev == -1 or nums[i] > nums[prev]){
                    pick = 1 + dp[i+1][i+1];
                }

                dp[i][prev+1] = max(pick, notPick);
            }
        }
        return dp[0][-1+1];
    }
};