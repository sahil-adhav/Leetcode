class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> sortedList;
        int left = 0, right = 0;
        int len = nums.size();
        
        while(right < len){
            if(right + 1 < len && nums[right+1] == nums[right]+1){
                right++;
            }else{
                string sortedRanges = to_string(nums[left]);
                if(left != right){
                    sortedRanges += "->" + to_string(nums[right]);
                }
                sortedList.push_back(sortedRanges);
                right++;
                left = right;
            }
        }
        return sortedList;
    }
};