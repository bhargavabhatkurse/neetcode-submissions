class Solution {
public:
unordered_map<int,int> dp;
    int rec(int n, vector<int>& perfects) {
        if(n == 0) return 0;
        int min_ = INT_MAX;

        if(dp.count(n)) return dp[n];

        for(int i = 0; i < perfects.size();i++){
        if(n >= perfects[i])
        min_ = min(min_, 1+rec(n-perfects[i],perfects)); 
        }

        return dp[n] = min_;
    }

    int numSquares(int n) {
       vector<int> perfects;

       for(int i = 1; i <= sqrt(n); i++) { //0 is not perfect square
        if(i*i <= n) perfects.push_back(i*i);
       } 

       for(auto i: perfects) {
        cout<<i<<" ";
       }
        
       
       return rec(n,perfects);

    }
};