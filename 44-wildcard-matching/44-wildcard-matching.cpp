class Solution {
public:
    
        bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        //Base Case
        if(i==0 and j==0) return true;
        
        if(i==0 and j>0){
            for(int ii=1; ii<=j; ii++){
                if(p[ii-1] != '*'){
                    return false;
                }
            }    
            return true;
        }
        
        if(i>0 and j==0){
            for(int ii=1; ii<=i; ii++){
                if(s[ii-1] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        //Calculation Part
        if(s[i-1] == p[j-1] or s[i-1] == '?' or p[j-1] == '?'){
            return dp[i][j] = f(i-1, j-1, s, p, dp);
        }
        
        if(s[i-1] == '*' or p[j-1] == '*'){
            return dp[i][j] = f(i-1, j, s, p, dp) || f(i, j-1, s, p, dp);
        }
        
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        //Base Cases
        dp[0][0] = true;
        
        for(int j=1; j<=m; j++){
            bool flag = true;
            for(int ii=1; ii<=j; ii++){
                if(p[ii-1] != '*'){
                    flag = false;
                }
            }
            dp[0][j] = flag;
        }
        
        for(int i=1; i<=n; i++){
            bool flag = true;
            for(int ii=1; ii<=i; ii++){
                if(s[ii-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == p[j-1] or s[i-1] == '?' or p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }

                else if(s[i-1] == '*' or p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }

                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};


