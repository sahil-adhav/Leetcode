class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        
        for(int curr=0; curr<n; curr++){
            for(int prevInd=0; prevInd<curr; prevInd++){
                if(nums[prevInd] < nums[curr]){
                    dp[curr] = max(1 + dp[prevInd], dp[curr]);
                }
            }
            maxi = max(maxi, dp[curr]);
        }
        return maxi;
    }
};