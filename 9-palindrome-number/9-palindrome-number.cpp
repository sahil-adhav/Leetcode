class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        int rev = 0;
        
        if(n < 0 || (n % 10 == 0 && n != 0)){
            return false;
        }
        
        while(rev < n){
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }
        return n == rev || n == rev/10;
    }
};