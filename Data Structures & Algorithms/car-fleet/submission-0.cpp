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
        
        vector<double> st; //using a vector like a stack here
        
        for(auto& x : cars) {
            st.push_back((double)(target - x.first)/x.second); //time to reach the target
            
            //if atleast  2 cars & //previous car needs less time than the car ahead, they will merge
            if(st.size() >= 2 && st[st.size()-1] <= st[st.size()-2]) {
                st.pop_back();
            }
        }
        return st.size(); //no of fleets
    }
};
