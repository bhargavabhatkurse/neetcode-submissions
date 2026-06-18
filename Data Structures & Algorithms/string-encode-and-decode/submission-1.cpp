class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for(auto& s: strs) {
            int size = s.size();
            res.append(to_string(size));
            res.push_back('#');
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while(i < s.size()) {        
            string number; 
            
            while(s[i] != '#') {
                number.push_back(s[i]);
                i++;
            }

            i++; //skip #

            int int_number = stoi(number);
            
            string temp; 
            while(int_number > 0 ) {
                temp.push_back(s[i]);
                i++;
                int_number--;
            }
            
            result.push_back(temp);
        }
        return result;
    }
};
