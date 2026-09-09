class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        

        int fives = 0, tens = 0;
        for(int i = 0; i < bills.size();i++) {
           if(bills[i] == 5) {
            fives++;
           }
           else if(bills[i] == 10) {
            fives--;
            tens++;
           }
           //if 20 and we have 10
           else if(tens > 0) { //use tens first in case of 20
            //decrement 5 and 10 both
            fives--;
            tens--;
           }
           //if 20 and no 10s
           else {
            fives -= 3;
           }
           if(fives < 0) return false;
         }
         return true;
    }
};