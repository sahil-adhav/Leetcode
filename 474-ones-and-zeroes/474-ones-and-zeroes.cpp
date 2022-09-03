class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int cntOne, cntZero;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(auto &str : strs){
            cntOne = 0;
            cntZero = 0;
            
            for(auto c : str){
                if(c == '0'){
                    cntZero++;
                }
                else if(c == '1'){
                    cntOne++;
                }   
            }
            for(int i=m; i>=cntZero; i--){
                for(int j=n; j>=cntOne; j--){
                    dp[i][j] = max(dp[i][j], dp[i - cntZero][j - cntOne]+1);            
                }
            }
        }
        
        
        return dp[m][n];
    }
};