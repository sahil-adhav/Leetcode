class Solution {
public:
    int reverse(int x) {
        int n = x;
        int ans = 0;
        while(n != 0){
            int digit = n % 10;
            n /= 10;
            if((ans > 0 && ans > (INT_MAX-digit)/10) | (ans < 0 && ans < (INT_MIN-digit)/10)){
                return 0;
            }
            ans = ans * 10 + digit;
        }
        return ans;
    }
};

// if ((rev > 0 && rev > (INT_MAX - digit)/10) | (rev < 0 && rev < (INT_MIN - digit)/10)) return 0;