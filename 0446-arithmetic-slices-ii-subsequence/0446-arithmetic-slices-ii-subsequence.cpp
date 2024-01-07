class Solution {
public:
    int solve1(vector<int>&nums,int i,long long diff,vector<unordered_map<long long int,int>>&dp){
        if(i >= nums.size())
            return 0;
        if(dp[i].find(diff) != dp[i].end())
            return dp[i][diff];

        int ans = 0;
        int index = i+1;
        for(index;index < nums.size();index++)
            if(nums[index] == (long long)nums[i] + (long long)diff)
                ans = ans + 1 + solve1(nums,index,diff,dp);
        return dp[i][diff] = ans;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        vector<unordered_map<long long int,int>> dp(nums.size());
        for(int i = 0;i < nums.size();i++){
            for(int j = i+1;j < nums.size();j++){
                long long diff = (long)nums[j] - (long)nums[i];
                if(diff >= INT_MAX || diff <= INT_MIN)
                    continue;
                int d = solve1(nums,j,diff,dp);
                ans += d;
            }
        }
        return ans;
    }
};