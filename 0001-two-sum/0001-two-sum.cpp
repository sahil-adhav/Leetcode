class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> pair;
        int len = nums.size();
        for(int i=0; i<len-1; i++){
            for(int j=i+1; j<len; j++){
                if(nums[i] + nums[j] == target){
                    pair.push_back(i);
                    pair.push_back(j);
                }
            }
        }
        return pair;
    }
};