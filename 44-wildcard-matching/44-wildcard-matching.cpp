class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n, m, s, p, dp);
    }
    
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
};


