class Solution {
public:
    
    void help(int ind, vector<vector<int>>& ans, vector<int>& nums){
        //Base Condition or when condition satisfies
        if(ind >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        //Calculation
        for(int i=ind; i<nums.size(); i++){
            swap(nums[i], nums[ind]);
            help(ind+1, ans, nums);
            swap(nums[i], nums[ind]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        help(0, ans, nums);
        
        return ans;
    }
};