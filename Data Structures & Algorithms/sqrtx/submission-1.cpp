class Solution {
public:
    int mySqrt(int x) {
        //binary search
        int l = 0, h = x;
        int ans;

        while(l<=h) {
            int i = l + (h-l)/2;

            if((long long)i*i > x) {
                h = i-1;
            }
            else if((long long)i*i < x) {
                l = i +1;
                ans = i; //possible answer
            }
            else return i; //important to do this
        }
        return ans;
    }
};