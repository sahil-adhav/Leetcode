class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 1;
        
        for(int curr=1; curr<n; curr++){
            for(int prev=0; prev<curr; prev++){
                if(nums[curr] > nums[prev] and dp[curr] < dp[prev] + 1){
                    dp[curr] = 1 + dp[prev];
                    cnt[curr] = cnt[prev];
                }
                else if(nums[curr] > nums[prev] and dp[curr] == 1 + dp[prev]){
                    cnt[curr] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[curr]);
        }
            
        int nos = 0;
        for(int i=0; i<n; i++){
            if(dp[i] == maxi){
                nos += cnt[i];
            }
        }
        return nos;
    }
};