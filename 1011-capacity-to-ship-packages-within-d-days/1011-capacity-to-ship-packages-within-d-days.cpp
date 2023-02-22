class Solution {
public:
    
    bool isPossible(vector<int>& weights, int days, int mid){
        int daysCount = 1;
        int capacity = 0;
        int n = weights.size();
        for(int i=0; i<n; i++){
            if(capacity + weights[i] <= mid){
                capacity+=weights[i];
            }else{
                daysCount++;
                if(daysCount > days){
                    return false;
                }
                capacity = weights[i];
            }
        }
    return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int start= *max_element(weights.begin(), weights.end());
        int sum=0;
        int n = weights.size();
        
        for(int i=0; i<n; i++){
            sum+=weights[i];
        }
        
        int end = sum;
        int ans = -1; 
        
        while(start <= end){
            int mid = start+(end-start)/2;
            if(isPossible(weights, days, mid)){
                ans = mid;
                end = mid-1;
            }else{
                start=mid+1;
            }
        }
    return ans;
    }
};