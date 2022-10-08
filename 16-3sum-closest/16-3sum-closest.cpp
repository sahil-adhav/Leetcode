class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int tmpAns = 0;
        int ans = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < len - 2; i++)
        {
            int left = i + 1;
            int right = len - 1;
            
            while(left < right)
            {
                tmpAns = nums[i] + nums[left] + nums[right];
                
                if(abs(ans - target) > abs(tmpAns - target))
                {
                    ans = tmpAns;
                }
                
                if(tmpAns > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return ans;
    }
};