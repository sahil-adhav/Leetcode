class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int,int> mpp;
        int minOp = 0;
        
        for(auto num : nums){
            mpp[num]++;
        }
        
        for(auto mp : mpp){
            int occurence = mp.second;
            if(occurence == 1){
                return -1;
            }
            minOp += ceil((double)occurence/3);
            // if(occurence % 3){
            //     minOp++;
            // }
        }
        
        return minOp;
    }
};