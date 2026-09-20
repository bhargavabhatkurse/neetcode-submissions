class Solution {
public:
    //greedy: choose the max freq element and add it (unless it is invalid(3 in a sequence) or count is 0)
    string longestDiverseString_(int a, int b, int c) {
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

        ///////////
        //using priority_queue
         string longestDiverseString(int a, int b, int c) {
            string ans = ""; 
            priority_queue<pair<int,char>> q;
            if(a > 0) q.push({a,'a'});
            if(b > 0) q.push({b,'b'});
            if(c > 0) q.push({c,'c'});

            while(!q.empty()) {
                auto [count,ch] = q.top();
                q.pop();


                if(ans.size() >=2 && ans[ans.size()-1] == ch && ans[ans.size()-2] == ch) {
                        if(q.empty()) break; //no other char is available
                        auto [count2, ch2] = q.top(); //find second max
                        q.pop();

                        ans += ch2;
                         if(--count2 > 0) q.push({count2,ch2}); //push the second max (if it is still remaining)
                        q.push({count,ch});
                }

                else {
                    ans += ch;
                    if(--count > 0) q.push({count,ch});
                }
            }


            return ans;
    }
};