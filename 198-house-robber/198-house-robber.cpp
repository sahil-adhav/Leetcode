class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return f(n-1, dp, nums);
    }
    
    int f(int ind, vector<int> &dp, vector<int> &nums){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int notPick = f(ind-1, dp, nums);
        int pick = nums[ind] + f(ind-2, dp, nums);
        
        return dp[ind] =  max(pick, notPick);
    }
};