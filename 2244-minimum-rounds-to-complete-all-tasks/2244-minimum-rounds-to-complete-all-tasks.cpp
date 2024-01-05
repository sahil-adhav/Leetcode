class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int minRounds = 0;
        unordered_map<int,int> mpp;
        
        for(auto task : tasks){
            mpp[task]++;
        }
        
        for(auto mp : mpp){
            int occurence = mp.second;
            
            if(occurence == 1){
                return -1;
            }
            
            minRounds += ceil((double)occurence / 3);
        }
        
        return minRounds;
    }
};