class Solution {
public:  
    unordered_map<int,int> dp;
     vector<int> path;
    int rec(int num) {
        if(num == 1) return 1; //can't be broken down more
        if(dp.count(num)) return dp[num];
        int res = 0;

        for(int i =1; i < num; i++) {
            int val = max(i, rec(i))*max(num - i, rec(num - i));
            res = max(res,val);
        }
        return dp[num] = res;
    }

    int integerBreak(int n) {
        return rec(n);
    }
};