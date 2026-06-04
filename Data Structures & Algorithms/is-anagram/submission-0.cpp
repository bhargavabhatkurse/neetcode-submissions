class Solution {
public:
    bool isAnagram(string s, string t) {

        map<char,int> m1 = {};
        map<char,int> m2 = {};

        //for the first time when we access a key not
        //present in map, it gets assigned 0 value in the map
        for(char i: s)
            m1[i] += 1; 
        
        for(char i: t)
            m2[i] += 1;

        if(m1 == m2)
            return true;
        else return false;
        
    }
};
