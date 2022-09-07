class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    ans.emplace_back(i);
                    ans.emplace_back(j);
                }
            }
        }
        return ans;
    }
};