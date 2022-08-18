class Solution {
public:
    
    void help(int ind, vector<int>& res, vector<vector<int>>& ans, vector<int>& nums){
        ans.push_back(res);
        for(int i=ind; i<nums.size(); i++){
            res.push_back(nums[i]);
            help(i+1, res, ans, nums);
            res.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        vector<vector<int>> ans;
    
        help(0, res, ans, nums);
            
        return ans;    
    }
};