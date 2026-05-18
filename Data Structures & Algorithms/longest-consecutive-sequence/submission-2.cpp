class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check(nums.begin(), nums.end());
        int maxc = 0;

        for(auto x: nums){
            if(check.find(x-1) == check.end()){
                int cur = x;
                int temp = 1;
                while(check.count(cur+1)){
                    cur++;
                    temp++;
                }
                maxc = max(maxc, temp);
            }
        }
        return maxc;
    }
};