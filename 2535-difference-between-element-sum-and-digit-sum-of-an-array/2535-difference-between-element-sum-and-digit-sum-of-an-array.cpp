class Solution {
public:
    
    int digitSumOfNumber(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
    int differenceOfSum(vector<int>& nums) {
        int ans = 0, elementalSum = 0, digitSum = 0;
        
        for(int i=0; i<nums.size(); i++){
            elementalSum += nums[i];
        }
        
        for(int i=0; i<nums.size(); i++){
            digitSum += digitSumOfNumber(nums[i]);
        }
        
        ans = abs(digitSum - elementalSum);
        
        return ans;
    }
};