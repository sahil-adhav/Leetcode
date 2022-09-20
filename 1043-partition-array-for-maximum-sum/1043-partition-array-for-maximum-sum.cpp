class Solution {
public:
    
    int f(int i, int n, int k, vector<int> &arr, vector<int> &dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int maxi = -1e9, maxAns = -1e9, len = 0;
        for(int j=i; j< min(n, i+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len * maxi) + f(j+1, n, k, arr, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[i] = maxAns;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, n, k, arr, dp);
    }
};