class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long totalGifts = 0;
        int len = gifts.size();
        
        for(int i=0; i<k; i++){
            int maxInd = -1;
            int maxGifts = INT_MIN;
            
            for(int j=0; j<len; j++){
                if(gifts[j] > maxGifts){
                    maxGifts = gifts[j];
                    maxInd = j;
                }
            }
            
            //base case
            if(maxGifts == 0){
                break;
            }
            
            gifts[maxInd] = int(floor(sqrt(maxGifts)));
        }
        
        for(int i=0; i<len; i++){
            totalGifts += gifts[i];
        }
        
        return totalGifts;
    }
};