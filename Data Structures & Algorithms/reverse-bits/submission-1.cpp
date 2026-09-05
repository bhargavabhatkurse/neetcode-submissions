class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //o(32) -> o(1)

        uint32_t x = 0;

        for(int i = 0; i < 32; i++) {
            uint32_t digit =  n>>i & 1;
            x = x | digit<<(31-i); // | has lower prcedence than << (therefore this works fine)
            //x = x + (digit<<(31-i));// () is to be added because + has higher precedence than <<
            //therefore might evaluate as x = (x + digit)<<(31-i); which is wrong
            }   

        return x;


    }
};
