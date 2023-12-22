class Solution {
public:
    int maxScore(string s) {
        int rightZeroes = 0, leftZeroes = 0;
        int len = s.length() - 1;
        
        for(char c : s){
            if(c == '1'){
                rightZeroes++;
            }
        }
        
        int score = 0;
        for(int i=0; i<len; i++){
            if(s[i] == '0'){
                leftZeroes++;
            }
            else{
                rightZeroes--;
            }
            score = max(score, leftZeroes+rightZeroes);
        }
        
        return score;
    }
};