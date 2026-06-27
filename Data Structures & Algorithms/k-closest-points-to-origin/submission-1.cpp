class Solution {
public:
int euclid(vector<int>& point) {
    return point[0] * point[0] + point[1] * point[1]; 
}

int partition(vector<vector<int>>& points, int l, int r) {
    int p_idx = r;
    int j = l;
    int pivot_dist = euclid(points[p_idx]);

    for(int i = l; i < r; i++) { 
        if(euclid(points[i]) <= pivot_dist) {
            swap(points[i], points[j]);
            j++; //I will change regardless of this if block
        }
    }
    swap(points[j],points[r]); //swap with the pivot
    return j;
}

int partition_2(vector<vector<int>>& points, int l, int r) {
    int p_idx = l;
    int i = l+1;
    int j = r;
    int pivot_dist = euclid(points[p_idx]);

    while(true) {
        while(i <= r && euclid(points[i]) <= pivot_dist) i++;
        while(j > l && euclid(points[j]) >= pivot_dist) j--; //j should not go till the pivot so j>l

        if(i > j) break;

        swap(points[i],points[j]);
    }

    swap(points[j],points[l]); //swap with the pivot
    return j;
}


vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //quick select method
        //after partioning, the pivot goes to the corerct index

        int target = k-1; //3 closest means till 0,1,2 index
        int left = 0, right = points.size()-1;
        int pivot = points.size(); //initially

        while(pivot != target) {
            pivot = partition_2(points,left,right);
            if(pivot < target) left = pivot + 1;
            else right = pivot -1;
        }

        return vector<vector<int>>(points.begin(),points.begin()+ k); //remember this syntax

    }
};
