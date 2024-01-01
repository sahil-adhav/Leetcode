// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lower = 1, higher = n, mid;
        
        while(lower < higher){
            mid = lower + (higher - lower)/2;
            if(!isBadVersion(mid)){
                lower = mid + 1;
            }
            else{
                higher = mid;
            }
        }
        return lower;
    }
};