class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minOp = 0;
        map<int,int> mpp;
        
        for(auto num : nums){
            mpp[num]++;
        }
        
        for(auto mp : mpp){
            int occurence = mp.second;
            if(occurence == 1){
                return -1;
            }
            minOp += occurence / 3; 
            if(occurence % 3 != 0){
                minOp++;
            }
        }
        
        return minOp;
    }
};
