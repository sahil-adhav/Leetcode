class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        
        if(n == 0 || n == 1){
            return;
        }
        
        while(right < n){
            if(nums[right] == 0){
                right++;
            }
            else{
                swap(nums[left++], nums[right++]);
            }
        }
    }
};