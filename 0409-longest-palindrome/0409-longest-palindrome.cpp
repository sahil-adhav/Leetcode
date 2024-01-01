class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.length();
        unordered_map<char, int> mpp;
        int oddCounter = 0;
        
        for(int i=0; i<len; i++){
            mpp[s[i]]++;
            if(mpp[s[i]] % 2 == 1){
                oddCounter++;
            }
            else{
                oddCounter--;
            }
        }
        return oddCounter > 1 ? len - oddCounter + 1 : len;
    }
};