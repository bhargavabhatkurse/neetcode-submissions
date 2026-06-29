class Solution {
public:
    int characterReplacement_bruteforce(string s, int k) {
        int res = 0;
       
        for(int i = 0; i < s.size(); i++) {
             unordered_map<char,int> m;
             int maxf = 0;
             for(int j = i; j < s.size(); j++){
                m[s[j]]++;
                
                // for(auto [c,f]: m) {
                //     maxf = max(maxf,f);
                // }

                maxf = max(maxf, m[s[j]]); //this is better

                if(((j-i+1))-maxf <=k) res = max(res,j-i+1);
             }
        }
        return res;
    }

     int characterReplacement_sliding(string s, int k) {
        int res = 0;
        unordered_set<char> chst(s.begin(),s.end());
        
        for(char ch: chst) {
        int l = 0; // start of the window, r is the end of the window
        int count = 0; //count of the current character s in the window
        
        for(int r = 0; r < s.size(); r++) {
           if(s[r] == ch) {
            count++;
           }

       

        while((r-l+1) - count > k) { //shift the window
            if(s[l] == ch) 
            count--;

            l++;
        }    

        res = max(res, r-l+1);   
        }
        }
        return res;
    }


    int characterReplacement(string s, int k) {

        //optimal - we don't need to check for each character

        //beacuse we will always be replacing others with the most frequent element
        int res = 0;
        unordered_map<char, int> count;
        int l = 0,maxf = 0; // start of the window, r is the end of the window
        //maxf keeps the track of the maxf of an elemnt in the window
     
        for(int r = 0; r < s.size(); r++) {
            count[s[r]]++;
    

            maxf = max(maxf,count[s[r]]); //I will always be replacing others, not the max character

            while((r-l+1) - maxf > k) { //shift the window
                count[s[l]]--;
                l++;

            //we let the maxf be stale as stale maxf will delay the shrink, not not affect correctness
            //we can do something like this but it will cost more computation
            
                // maxf = 0;
                // for (auto [c, f] : count)
                //     maxf = max(maxf, f);
        }    

        res = max(res, r-l+1);   
        }
        return res;
    }
};
