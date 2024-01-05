class Solution {
public:
    int climbStairs(int n) {
        vector<int> ways(n+1);
        
        if(n <= 2){
            return n;
        }
        
        ways[1] = 1;
        ways[2] = 2;
        
       for(int i=3; i<=n; i++){
           ways[i] = ways[i-1] + ways[i-2];
       }
        
        return ways[n];
    }
};