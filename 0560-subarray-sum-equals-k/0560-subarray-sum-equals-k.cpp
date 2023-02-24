class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        
        for(int i=0; i<n; i++){
            sum += nums[i];
            int findSum = sum - k;
            if(mpp.find(findSum) != mpp.end()){
                ans += mpp[findSum];
            }
            mpp[sum]++;
        }
        
        return ans;
    }
};