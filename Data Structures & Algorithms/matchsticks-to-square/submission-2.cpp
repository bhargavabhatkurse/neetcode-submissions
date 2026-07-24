class Solution {
public:
    bool backtracking_brute(vector<int>& matchsticks, vector<int>& sides, int i) {
        //The time complexity is 4n because of the branching factor of the recursion tree.
        // for each matchstick, we are trying to place it in 4 sides 
        if(i == matchsticks.size()) return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]; //true if all sides are equal

        for(int j = 0; j < 4; j++) { //choose a side to use the ith matchstick
            sides[j] += matchsticks[i];
            if(backtracking_brute(matchsticks,sides,i+1)) return true; //found a solution
            sides[j] -= matchsticks[i];
            //try another side;
        }
        return false; //if no solution (important to return false)
    } 
    
    
    bool makesquare_brute(vector<int>& matchsticks) {
        //TLE

        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum % 4 != 0 ) return false;
        vector<int> sides(4,0); //4 sides intially of length 0
        return backtracking_brute(matchsticks,sides,0); //i: index of the current matchstick
    }





    bool backtracking_prune(vector<int>& matchsticks, vector<int>& sides, int i, int length) {
      
        if(i == matchsticks.size()) return true;

        for(int j = 0; j < 4; j++) { //choose a side to use the ith matchstick
            if(sides[j] + matchsticks[i] <= length) {
            sides[j] += matchsticks[i];
            if(backtracking_brute(matchsticks,sides,i+1)) return true; //found a solution
            sides[j] -= matchsticks[i];
            }

            if(sides[j] == 0) break; //this side j was originally empty, and we coulnd't find a soln
            //thefore, trying another empty side is not worth it as it is symmetrical
        }
        return false; //if no solution (important to return false)
    } 


    bool makesquare(vector<int>& matchsticks) {
        //pruning
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum % 4 != 0 ) return false;
        vector<int> sides(4,0); //4 sides intially of length 0
        int length = sum/4;
        sort(matchsticks.rbegin(), matchsticks.rend()); //reverse sorting helps to identify the failure cases faster by trying larger matchsticks first
        return backtracking_prune(matchsticks,sides,0,length); //i: index of the current matchstick
    }
};