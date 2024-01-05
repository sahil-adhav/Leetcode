class Solution {
public:
    int climbStairs(int n) {
        int ways = 0;
        
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int twoStepsBeforeN = 1;
        int oneStepBeforeN = 2;
        
        for(int i=2; i<n; i++){
            ways = twoStepsBeforeN + oneStepBeforeN;
            twoStepsBeforeN = oneStepBeforeN;
            oneStepBeforeN = ways;
        }
        
        return ways;
    }
};