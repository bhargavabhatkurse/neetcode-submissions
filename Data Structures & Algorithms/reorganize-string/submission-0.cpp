class Solution {
public:
    string reorganizeString(string s) {
         map<char, int> m; 
        priority_queue<pair<int, char>> pq; //we only care about the frequency, not the character

        
        for(auto i: s) { //find the frequency of the task
           m[i]++;
        }

        for(auto [ch,freq]: m) {
            if(freq > 0) //if positive count of this char
            pq.push({freq,ch}); //add it
        }

        string res = "";
        pair<int, char> prev = {0, '#'};

        while(!pq.empty()) {
            auto [freq,ch] = pq.top();
            pq.pop();

            res += ch;
            freq--;

            if(prev.first > 0) {
                pq.push(prev); //add that character again
            }

            prev  = {freq,ch}; 
        }
        
        //edge case
        if(res.size() != s.size()) return "";
        
        
        return res;
    }
};