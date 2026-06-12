class Twitter {
public:
    int t=0;
    unordered_map<int,vector<pair<int,int>>> tweet;
    unordered_map<int,unordered_set<int>> followers;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        t++;
        tweet[userId].push_back({t,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto comp=[](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(comp)> mh(comp);
        followers[userId].insert(userId);
        for(auto f:followers[userId]){
            if(tweet.find(f)!=tweet.end()){
                int index=tweet[f].size()-1;
                pair<int,int> post = tweet[f][index];
                mh.push({post.first,post.second,f,index-1});
            }
        }
        while(!mh.empty() && res.size()<10){
            vector<int> recent=mh.top();
            mh.pop();
            res.push_back(recent[1]);
            if(recent[3]>=0){
                pair<int,int> post = tweet[recent[2]][recent[3]];
                mh.push({post.first,post.second,recent[2],recent[3]-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
