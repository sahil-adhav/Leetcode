class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        while(num){
            ans += num % 10;
            num = num/ 10;
        }
        if(ans <= 9){
            return ans;
        }
        return addDigits(ans);
    }
};