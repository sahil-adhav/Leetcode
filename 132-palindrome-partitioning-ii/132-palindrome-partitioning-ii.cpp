class Solution {
public:
    
    
    bool isPalindrome(int i, int j, string &temp){
        while(i < j){
            if(temp[i++] != temp[j--]){
                return false;
            }
        }
        return true;
    }
    
    int f(int i, int n, string &s, vector<int> &dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int mini = 1e9;
        for(int j=i; j<n; j++){
            if(isPalindrome(i, j, s)){
                int cut = 1 + f(j+1, n, s, dp);
                mini = min(mini, cut);
            }
        }
        return dp[i] = mini;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            int mini = 1e9;
            for(int j=i; j<n; j++){
                if(isPalindrome(i, j, s)){
                    int cut = 1 + dp[j+1];
                    mini = min(mini, cut);
                }
            }
            dp[i] = mini;  
        }
        return dp[0] - 1;
    }
};