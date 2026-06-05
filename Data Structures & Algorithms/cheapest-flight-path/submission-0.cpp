class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> prices(n,INT_MAX);
        prices[src] = 0;

        for(int i=0;i<=k;i++) //relax k+1 times
        {
            vector<int> temp = prices; //need to maintain a temp array
                                       // to avoid using more than 1 edges in the same iteration
            for(const auto& flight: flights) {
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];
            if (prices[s] == INT_MAX) //otherwise, INT_MAX+p will cause overflow in next line
                  continue;
            if(temp[d] > prices[s]+p) temp[d] = prices[s]+p;
            
            }
            prices = temp;
        } 
        return prices[dst] == INT_MAX? -1: prices[dst];

    }
};
