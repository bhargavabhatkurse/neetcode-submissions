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

    vector<int> findClosestElements__(vector<int>& arr, int k, int x) {
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

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //binary search
        int l = 0, r = arr.size()-1;
        int ans = arr.size();
        //find where x might fit in the array
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(arr[mid] >= x) { //if upper bound, do > not >=
                ans = mid; //lower bound
                r = mid -1;
            }
            else l = mid +1;
        }

        //now we will expand outwards
        l = ans-1; //closest will be immediately left to the upper bound of x
        r = ans;
        //l and r are outside the window: therefore the actual window is [l+1,....r-1]

        while((r-1) -(l + 1) + 1 <  k) { //actual window size (r-1) -(l + 1) + 1 = r-l-1
            if(l < 0) r++;
            else if(r >=arr.size()) l--;
            else if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                l--;
            } else {
                r++;
            }
        }
        
        return vector<int>(arr.begin() + l+1   , arr.begin() + r);

    }
};