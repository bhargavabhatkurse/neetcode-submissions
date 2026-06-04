class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;

        int min_size = min(s1.length(),s2.length());

        for (char c : s1) {
        map1[c]++; 
        }

        for(int i=0;i<=s2.size()-min_size;i++) {
        for(int j=0;j<min_size;j++)
            map2[s2[i+j]]++; 
        if(map2 == map1) return true;
            map2.clear();
         }
        return false;
}
};
