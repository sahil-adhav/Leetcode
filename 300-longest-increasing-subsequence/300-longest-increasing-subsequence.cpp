class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i=1; i<n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) 
                    - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4

// => 2 3 7 101  
    
// Binary Search

// 3 5 18 101 


// 10 101

// 9 101
    
// 2 5 7 101
    
// 3 7 101