class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res={{}};
        sort(nums.begin(),nums.end());
        int start = 0;
        for(int i=0;i<nums.size();i++){
            int end = res.size();
            if(i != 0 && nums[i] != nums[i-1]) start=0;
            for(int j = start; j < end; j++){
                vector<int> subset = res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }
            start=end;
        }
        return res;
    }
};
