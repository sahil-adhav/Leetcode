class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1, lastIndex = 0;
        vector<int> dp(n, 1), hash(n);
        
        sort(nums.begin(), nums.end());
        for(int curr=0; curr<n; curr++){
           hash[curr] = curr;
           for(int prevInd=0; prevInd<curr; prevInd++){
               if(nums[curr] % nums[prevInd] == 0 && 1+dp[prevInd] > dp[curr]){
                   dp[curr] = 1 + dp[prevInd];
                   hash[curr] = prevInd;
               }
           }
           if(dp[curr] > maxi){
               maxi = dp[curr];
               lastIndex = curr;
           }
        }
        
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};