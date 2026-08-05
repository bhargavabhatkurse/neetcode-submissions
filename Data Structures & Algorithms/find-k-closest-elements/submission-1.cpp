class Solution {
public:
    vector<int> findClosestElements_heap(vector<int>& arr, int k, int x) {
        auto cmp = [x](int a, int b) {
            int dist_a = abs(x-a);
            int dist_b = abs(x-b);

            if(dist_a == dist_b) return a>b;
            else return dist_a > dist_b;
        };
        
        vector<int> ans;

        priority_queue<int, vector<int>,decltype(cmp)> q(cmp);

        for(int i: arr) {
            q.push(i);
        }

        while(!q.empty() && k) {
            ans.push_back(q.top());
            q.pop();
            k--;
        }
        sort(ans.begin(),ans.end());

        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1;

        while(r - l >= k) //because we are finding a window of k
        {
            if(abs(x-arr[l]) <= abs(x-arr[r])) {
                r--; //shrink
            }
            else 
                l++; //shrink
        }

        return vector<int>(arr.begin() + l, arr.begin() + r + 1);


    }
};