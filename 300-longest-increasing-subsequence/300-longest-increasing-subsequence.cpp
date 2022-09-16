class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n, 1);
        int lastIndex = -1;
        int maxi  = -1;        
        for(int curr=0; curr<n; curr++){
            hash[curr] = curr;
            for(int prev=0; prev<curr; prev++){
                if(nums[prev] < nums[curr] && 1+dp[prev] > dp[curr]){
                    dp[curr] = 1 + dp[prev];
                    hash[curr] = prev;
                }
            }
            // maxi = max(maxi, dp[curr]);
  
        }
        
        for(int curr=0; curr<n; curr++){
           if(dp[curr] > maxi){
                maxi = dp[curr];
                lastIndex = curr;
            }
        }
        
        vector<int> lis;
        lis.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            lis.push_back(nums[lastIndex]);
        }
        reverse(lis.begin(), lis.end());
        for(auto it : nums) cout << it << " ";
        cout << endl;
        return maxi;
    }
};


// Input: nums = [10,9,2,5,3,7,101,18]
//      :   dp = [1, 1,1,2,2,3, 4 , 4]
    

// Output: 4