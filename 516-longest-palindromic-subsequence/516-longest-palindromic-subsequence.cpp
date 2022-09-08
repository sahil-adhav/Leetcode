class Solution {
public:
    int lcs(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        vector<int> prev(n2+1, 0), curr(n2+1, 0);
        
        // for(int i=0; i<=n1; i++){
        //     dp[i][0] = 0;
        // }
        
        for(int j=0; j<=n2; j++){
            prev[j] = 0;
        }
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1 +  prev[j-1];
                }
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[n2];
    }
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s,  t);
    }
};