class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s, p, dp);
    }
    
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        //Base Case
        if(i<0 and j<0) return true;
        
        if(i<0 and j>=0){
            for(int ii=0; ii<=j; ii++){
                if(p[ii] != '*'){
                    return false;
                }
            }    
            return true;
        }
        
        if(i>=0 and j<0){
            for(int ii=0; ii<=i; ii++){
                if(s[ii] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        //Calculation Part
        if(s[i] == p[j] or s[i] == '?' or p[j] == '?'){
            return dp[i][j] = f(i-1, j-1, s, p, dp);
        }
        
        if(s[i] == '*' or p[j] == '*'){
            return dp[i][j] = f(i-1, j, s, p, dp) || f(i, j-1, s, p, dp);
        }
        
        return dp[i][j] = false;
    }
};


