class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> seen;
        for(int x:nums)seen.insert(x);
        for(int i=0;i<nums.size();i++){
            int y=target-nums[i];
            if(seen.find(y)==seen.end()) continue;
            for(int j=0;j<nums.size();j++){
                if(nums[j]==y && i!=j)
                    if(i<j) return {i,j};
                    else return {j,i};
                else continue;
            }
        }
    }
};
