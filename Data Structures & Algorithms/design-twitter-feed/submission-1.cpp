class Twitter {
    int time;
    unordered_map<int, vector<vector<int>>> tweetMap;
    unordered_map<int, set<int>> followMap;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId}); 
    }
    
    vector<int> getNewsFeed(int userId) {
        //bruteforce - add all tweeets, sort and then take 10 
        vector<vector<int>> feed = tweetMap[userId]; //all your tweets
        for (int followeeId : followMap[userId]) {
            feed.insert(feed.end(), tweetMap[followeeId].begin(),
                                    tweetMap[followeeId].end());
        }
        sort(feed.begin(), feed.end(), [](auto &a, auto &b) {
            return a[0] > b[0]; //reverse sort to fetch the latest
        });

        vector<int> res;
        for (int i = 0; i < min(10, (int)feed.size()); ++i) {
            res.push_back(feed[i][1]);
        }
        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
         if (followerId == followeeId) return; 
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
