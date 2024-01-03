class Solution {
public:

    int countOwn(string& str, char look){
        int ans = 0;
        for(int i=0; i<str.length(); i++){
            if(str[i] == look){
                ans++;
            }
        }
        return ans;
    }
    
    int numberOfBeams(vector<string>& bank) {
        int len = bank.size();
        int previous = 0, current = 0, totalLines = 0;
        
        for(int i=0; i<len; i++){
            current = countOwn(bank[i], '1');
            if(current > 0){
                totalLines += current * previous;
                previous = current;
            }
        }
        return totalLines;
    }
};