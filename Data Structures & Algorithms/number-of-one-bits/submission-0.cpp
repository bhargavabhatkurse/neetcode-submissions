class Solution {
public:
    int hammingWeight(uint32_t n) {
    int mask = 1;
    int count = 0;
    for(int i = 0; i <31; i++) {
        if(n>>i & mask) count++;
        // if(n & mask<<i) count++; //this also works
    }
    //Brian kernighan's trick
    //when you subtract 1, rightmost bit becomes 0 and to its right become 1
    // n     = 1011000
    // n - 1 = 1010111
    int iteration = 0;
    while(n) {
        n &= n-1;
        iteration++;
    }

    return iteration;
    }
    
};
