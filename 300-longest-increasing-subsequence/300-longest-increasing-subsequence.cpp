class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i=0; i<n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) 
                    - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
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