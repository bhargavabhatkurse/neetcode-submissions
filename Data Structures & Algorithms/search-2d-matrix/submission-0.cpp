class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //bruteforce o(m*n) search every element

        //assume the 2d array is flattened 1d array and perform binary search
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n*m -1;
      
        while(low <= high) {
        int mid = low  + (high - low)/2;
        int r = mid/m, c = mid%m; //remember this conversion
        
        if(matrix[r][c] == target) return true;
        else if(matrix[r][c] <= target) low = mid +1;
        else high = mid -1;
        }
    
        return false;
    }
};
