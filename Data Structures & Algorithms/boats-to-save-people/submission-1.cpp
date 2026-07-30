class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //greedy: pair heaviest and lightest together
        //if they can't share the boat, only take the heaviest

        sort(people.begin(),people.end());

        int l = 0, r = people.size()-1;
        int boat = 0; //minimum number of boats

        while(l<=r) { //if only one remaining l == r, then I need to take only that one person. therefore, <= here
        if(people[l] + people[r] <= limit) {
            boat++;
            l++;
            r--;
        }
        else {
            boat++;
            r--;
        }
        }
        return boat;
    }
};