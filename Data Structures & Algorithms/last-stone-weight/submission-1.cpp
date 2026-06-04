class Solution {
    priority_queue<int, vector<int>> q;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int i: stones) q.push(i);

        while(q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();

            if(a == b) continue;
            else {
                int x = a - b ;
                q.push(x);
            }
        } 
        return q.size()?q.top(): 0;
    }
};
