class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = -1;
        int n = nums.size();
        int totalSum = n * (n + 1)/2;
        
        for(int i=0; i<n; i++){
            totalSum -= nums[i];
        }
        
        result = totalSum;
        
        return result;
    }
};