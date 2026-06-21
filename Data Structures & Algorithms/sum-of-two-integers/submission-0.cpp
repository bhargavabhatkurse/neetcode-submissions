class Solution {
public:
    int getSum(int a, int b) {
        //a and be can be negative here

         int size = sizeof(int) * 8; //no of bits
         int sum = 0;
         int carry = 0;

         for(int i = 0; i < size; i++) {
            int curr_bit = (a>>i & 1) ^ (b>>i & 1) ^ carry;
            carry = ((a>>i & 1) + (b>>i & 1) + carry >= 2) ? 1: 0; //carry generated or not
             if(curr_bit) { //if current bit is 1
                sum = sum | 1<<i; //set that bit of the sum as 1
             }
         }

         
         return sum;
    }
};
