class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //// bruteforce - o(n*m) - m: unique characters o(m) spce
        // int max_length = INT_MIN;
        
        // for(int i = 0 ; i < s.size(); i++) {
        //   int length = 1;
        //   unordered_set<char> st;
        //   st.insert(s[i]);
        //     for(int j = i+1 ; j < s.size(); j++) {
        //         if(st.count(s[j])) break;
        //         st.insert(s[j]);
        //         length++;
        //     }
        //     max_length = max(max_length, length);
        // }
        // return max_length;
    
    // //sliding window: 0(n) 0(m)
    // unordered_set<char> st;
    // int left = 0; 
    // //st.insert(s[left]); //initially the size is 1; then you need to start the loop from right = 1
    // int max_length = 0;

    // for(int right = 0; right < s.size(); right++) {
    //     if(st.count(s[right])) { //if s[right] is duplicate
    //         while(st.find(s[right]) != st.end()) { //till right character is eliminated
    //         st.erase(s[left]);
    //         left++;
    //         }
    //     }
    //     st.insert(s[right]);
    //     max_length = max(max_length, right - left + 1);

    // }
    //     return max_length;
    // }
     
     
    //sliding window: optimal  
    unordered_set<char> st;
    unordered_map<char,int> m;
    int left = 0; 
    int max_length = 0;

    for(int right = 0; right < s.size(); right++) {
        if(st.count(s[right])) { //if right is found
            left =  max(left, m[s[right]] + 1); //directly jump to the correct value of left
            //taking max because other wise there is a chance that left may move backwards.
        }
        st.insert(s[right]);
        m[s[right]] = right;
        max_length = max(max_length, right - left + 1);

    }
        return max_length;
    }

};
