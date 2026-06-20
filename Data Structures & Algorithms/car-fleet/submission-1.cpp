class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //we need to sort based on the position to get the starting positions on the lane.
        int n = position.size();
        vector<pair<int,int>> cars(n);
        for(int i = 0; i< n;i++) {
            cars[i] = {position[i],speed[i]};
        }
        sort(cars.rbegin(),cars.rend());// sort based on the position
        
        //now we will process from the end as the speed of the last car will limit
        //we need to push the last car and then the second last car and check if the 
        //second last car might intersect with the last car
        //then both of them will travel with the speed of the last car 
        
        stack<double> st; //using a normal stack (while using normal stack, verify first and then push)
        
        for(auto& x : cars) {
            double time = (double)(target - x.first)/x.second; //time to reach the target
            
            if(!st.empty() && st.top() >= time) {
                continue;
            }
            else
            st.push(time);
            
        }
        return st.size(); //no of fleets
    }
};
