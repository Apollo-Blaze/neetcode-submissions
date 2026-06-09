class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return {{}};
        vector<int> first = {nums[0]};
        vector<int> rest(nums.begin()+1, nums.end());
        vector<vector<int>> perms = permute(rest);
        vector<vector<int>> result;
        
        for(auto perm : perms){
            for(int i = 0; i <= perm.size(); i++){
                vector<int> temp = perm;
                temp.insert(temp.begin()+i, nums[0]);
                result.push_back(temp);
            }
        }
        return result;
    }
};
