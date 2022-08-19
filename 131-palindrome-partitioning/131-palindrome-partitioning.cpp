class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        solve(0, s, ans, res);
        return ans;
    }
    
    void solve(int ind, string s, vector<vector<string>>& ans, vector<string>& path){
        //Base Condition
        if(ind == s.size()){
            ans.push_back(path);
            return;
        }
        
        //Calculation Part
        for(int i=ind; i<s.size(); i++){
            if(palindrome(s, ind, i)){
                path.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, ans, path);
                path.pop_back();
            }
        }
    }
    
    // aab ==> a | ab
    // aab ==> aa | b
    // aab ==> a | a | b
    
    bool palindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
};