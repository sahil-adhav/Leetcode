class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        
        dp[0] = nums[0];
        
        for(int ind=1; ind<n; ind++){
            int notPick = dp[ind-1];
            int pick =nums[ind];
            if(ind > 1) pick += dp[ind-2];
            dp[ind] =  max(pick, notPick);
        }
        
        return dp[n-1];
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