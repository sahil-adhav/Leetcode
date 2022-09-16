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
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, dp, n, nums);
    }
};