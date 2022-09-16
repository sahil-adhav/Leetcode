class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi  = 1;        
        for(int curr=0; curr<n; curr++){
            for(int prev=0; prev<curr; prev++){
                if(nums[curr] > nums[prev]){
                    dp[curr] = max(dp[curr], 1+dp[prev]);
                }
            }
            maxi = max(maxi, dp[curr]);
        }
        return maxi;
    }
};


// Input: nums = [10,9,2,5,3,7,101,18]
//      :   dp = [1, 1,1,2,2,3, 4 , 4]   
    

// Output: 4