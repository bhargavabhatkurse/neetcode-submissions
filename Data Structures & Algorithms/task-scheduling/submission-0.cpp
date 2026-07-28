class Solution {
public:
    //greedy assumption: always select the maximum frequency task

    int leastInterval(vector<char>& tasks, int n) {
    
    map<char, int> m; //to find the max freq currently available task
    
    priority_queue<int> pq; //we only char about the frequency count, not the character
    
    queue<pair<int,int>> q; //how many count remaining and at what time t will they be available next

        for(char c = 'A'; c <= 'Z'; ++c) {
         m[c] = 0; // Initializes all 26 lowercase letters to 0
         }
        
        for(auto i: tasks) { //find the frequency of the task
           m[i] += 1;
        }

        for(auto [k,v]: m) {
            if(v > 0) //if positive count of this char
            pq.push(v); //we only care about the count
        }

        int time = 0;
        while(!pq.empty() || !q.empty()) { //till heap or the cooldown is not 
            time++; //time increases every iteration

            if(pq.empty()) //no more tasks: check the cooldown queue 
            {
                time = q.front().second; //directly jump to the time when the front of queue is available again
            }
            else { 
                int cnt = pq.top();
                pq.pop();
                cnt = cnt - 1; //one task is complete
                if(cnt > 0) //still this task type is remaining
                    q.push({cnt,time + n});//this task available next after n time
            }

            if(!q.empty() && q.front().second == time) { //task is ready after cooldown
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
