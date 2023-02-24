class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        
        for(int i=0; i<n; i++){
            if(mpp.find(target-nums[i]) == mpp.end()){
                mpp[nums[i]] = i; 
            }
            else{
                return {mpp[target-nums[i]], i};
            }
        }
        
        return {-1, -1};
    }
};