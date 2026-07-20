class Solution {
public:
vector<int> dp;
int rec(int n,int i) {
    if(i == 0) return 0;
    else if(i == 1) return 1;
    else if(i == 2) return 1;

    if(dp[i] != -1) return dp[i];

    return dp[i] = rec(n,i-1) + rec(n,i-2) + rec(n,i-3); 
}
    int tribonacci(int n) {
        //dp.assign(n+1,-1);
        //return rec(n,n);

        int t[] = {0, 1, 1};
        if (n < 3) return t[n];

        for (int i = 3; i <= n; ++i) {
            t[i%3] = t[0] + t[1] + t[2]; //overrides the oldest value which we don't ened
        }
        return t[n % 3];
    }
};