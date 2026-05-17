class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> res;
        for(auto x: nums) freq[x]++;
        while(k){
            int maxkey =-10000;
            int maxcount=0;
            for(auto x:freq){
                if(x.second>maxcount){ 
                    maxcount=x.second;
                    maxkey=x.first;
                }
            }
            res.push_back(maxkey);
            freq.erase(maxkey);
            k--;
        }
        return res;
    }
};
