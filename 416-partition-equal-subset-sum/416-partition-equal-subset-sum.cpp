class Solution {
public:
    
    bool can(int n, int k, vector<int>& nums){
        vector<bool> prev(k+1, 0), curr(k+1, 0);
        prev[0] = curr[0] = true;
        
        if(nums[0] <= k){
            prev[nums[0]] = true;  
        }
        
        for(int ind = 1; ind<n; ind++){
            for(int target=1; target<=k; target++){
                bool notTake = prev[target];
                bool take = false;
                if(nums[ind] <= target){
                    take = prev[target-nums[ind]];
                }
                curr[target] = take or notTake;
            }
            prev = curr;
        }
        return prev[k];
    }
    
    bool canPartition(vector<int>& nums) {
        int totSum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            totSum += nums[i];
        }
        if(totSum % 2) return false;
        int target = totSum / 2;
        return can(n, target, nums);
    }
};