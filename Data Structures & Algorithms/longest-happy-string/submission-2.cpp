class Solution {
public:
    //greedy: choose the max freq element and add it (unless it is invalid(3 in a sequence) or count is 0)
    string longestDiverseString(int a, int b, int c) {
        vector<int> count = {a,b,c};
        string ans = "";

        int repeated = -1; //initial

        while(true) {
            int maxCh = getmax(count,repeated);
            if(maxCh == -1) break; //no more max characters remaining
            
            ans += (char)(maxCh + 'a');

            count[maxCh]--;

            if(ans.size() >= 2 && ans.back() == ans[ans.size() -2]) //if repeated twice already
                repeated = maxCh; 
            else {
                repeated = -1; //reset repeated
            }
        }
        return ans;
    }

    int getmax(const vector<int>& count, int repeated) {
        int idx = -1, maxCnt = 0;

        for(int i = 0; i < 3; i++) {
            if(i == repeated || count[i] == 0) continue;

            //set new maxCh
            if(maxCnt < count[i]) {
                maxCnt = count[i];
                idx = i;
            }
        }

        return idx;



    }
};