class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> closetoOpen = { //to match appropriately
            {')', '('}, 
            {']', '['},
            {'}', '{'}
        };

        for(char c : s) {
            if(closetoOpen.count(c)) //if the closing character exists in the map
            //otherwise map might create new (risk)
            {
                if(!st.empty() && closetoOpen[c] == st.top()) st.pop();
                //always check if the stack is empty before popping. 
                
                else return false; //not matching or stack is empty
            }
            else st.push(c);//push if its an opening character
        }

        return st.empty(); //at the end st should be empty

    }
};
