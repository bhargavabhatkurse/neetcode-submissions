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
        dp.assign(n+1,-1);
        return rec(n,n);
    }
};