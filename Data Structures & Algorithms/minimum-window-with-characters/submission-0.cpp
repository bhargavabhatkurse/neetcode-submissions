class Solution {
public:
    string minWindow_bruteforce(string s, string t) {
        unordered_map<char,int> m;
        unordered_map<char,int> m1;
        //bruteforce - o(n2 * m) m(unique charaters in t) is the check the map again
        int minimum = INT_MAX;
        for(char i: t) m1[i]++;

        string ans= "";
        int i, j;

        for(i = 0; i < s.size();i++){
        m.clear();
        for(j = i; j < s.size();j++) { //starting from i to consider substr of size 1 
            m[s[j]]++;
            bool b = true; 

            //
            for(auto x: m1) {
                if(m[x.first] < x.second) { //eg ab and abba, the count of b is 1 < 2 (valid substring)
                    b = false;
                    break;
                }
            }

            if(b) {
            if(minimum > j-i+1) {
            minimum = j - i + 1;
            ans = s.substr(i, j - i + 1);
            }
        }
        }
    }
    return ans;


   
    
    }
    string minWindow(string s, string t) {
     //sliding window: avoid recomputing character counts for each starting index
     if(t.empty()) return "";
     unordered_map<char, int> T, window;
        
        for (char c : t) {
            T[c]++;
        }

        int l=0; //window left
        int have = 0, need = T.size(); //how many characters I need
        int resLen = INT_MAX; //we will find the minumum resLen
        pair<int,int> res = {-1,-1};

        for(int r = 0; r < s.size();r++) {
            char c = s[r];
            window[c]++;

            if(T.count(c) && window[c] == T[c]) //if this character exists in c and the 
                    have++; //only if the frequency also matches

            
            //only shrink when your window is valid
            while(have == need) {
                //max calculations
                 if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if(T.count(s[l]) && window[s[l]] < T[s[l]]) {
                    have--;
                }

                l++; //move forward



                //try to shrink the window
                // X -> 1
                // A -> 1
                // B -> 1
                // C -> 1
                // Y -> 1
                //if string is abc, this window is vaLid but we need to delete x by shrinking
                // The window is valid (have == need).
                // Try removing characters from the left.
                // If removing a character keeps the window valid,
                // that character was unnecessary.
                // Stop when removing a character would make the
                // window invalid.
            }
        }

        return resLen == INT_MAX? "" : s.substr(res.first,resLen);

    }
};
