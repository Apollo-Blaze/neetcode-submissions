class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto x: nums) freq[x]++;

        // index = frequency, value = list of numbers with that frequency
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto x: freq){
            bucket[x.second].push_back(x.first);
        }

        vector<int> res;
        // iterate from highest frequency to lowest
        for(int i = bucket.size()-1; i >= 0 && res.size() < k; i--){
            for(auto x: bucket[i]){
                res.push_back(x);
                if(res.size() == k) break;
            }
        }
        return res;
    }
};