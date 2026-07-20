class Solution {
public:
    
    int totalNQueens(int n)  {
    int res = 0;
    vector<string> arr(n, string(n,'.')); //blank grid
    nqueen(res,arr,n,0);
    return res;
    
    }

bool issafe(vector<string>& arr,int row,int col,int n) {
    for(int i = row;i>=0;i--)       //checking the column
    if(arr[i][col] == 'Q') return false;
    
    for(int i = row-1,j=col-1;i>=0 && j>=0;i--,j--)    // checking left diagonal
       if(arr[i][j] == 'Q') return false;
    
    for(int i = row-1,j=col+1;i>=0 && j<n;i--,j++)    // checking right diagonal
       if(arr[i][j] == 'Q') return false;
    
    return true;
}


void nqueen(int& res,vector<string>& arr,int n,int row) {
   if(row == n) {
       res += 1;
       return;
       }
    

    for(int col = 0;col<n;col++)
        if(issafe(arr,row,col,n)) {
        arr[row][col] = 'Q';
        nqueen(res,arr,n,row+1); 
        arr[row][col] = '.';
        }
}
};
