class Solution {
public:
    int reverse(int x) {
       long rev = 0;
       int n = abs(x);

       while(n) {
        int rem = n%10;
        rev = rev*10 + rem;
        n = n/10;
       }
        
        x < 0 ? rev = rev*-1: rev = rev;

        if(rev < INT_MIN || rev > INT_MAX) return 0; 
        else return rev;
    }
};
 