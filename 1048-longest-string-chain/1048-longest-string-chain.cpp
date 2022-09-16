class Solution {
public:
    
    bool checkPossible(string &s1, string &s2){
        if(s1.size() != s2.size()+1){
            return false;
        }
        
        int first=0;
        int second=0;
        
        while(first < s1.size()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        
        if(first == s1.size() and second == s2.size()){
            return true;
        }
        
        return false;
    }
        
    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int maxi = 1;
        
        for(int curr=1; curr<n; curr++){
            for(int prev=0; prev<curr; prev++){
                if(checkPossible(words[curr], words[prev])){
                    dp[curr] = max(dp[curr], dp[prev]+1);
                }
            }
            maxi = max(maxi, dp[curr]);
        }
        
        return maxi;
    }
};