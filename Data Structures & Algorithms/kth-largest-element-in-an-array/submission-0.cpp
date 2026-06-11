class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> mh;
        for(auto x:nums){
            mh.push(x);
            if(mh.size()>k) mh.pop();
        }
        return mh.top();
    }
};
