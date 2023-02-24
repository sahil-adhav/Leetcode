class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ansFinal = INT_MIN;
        int n = nums.size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                ans++;
            }
            else{
                
                ans = 0;
            }
            ansFinal = max(ansFinal, ans);
        }
        return ansFinal;
    }
};