class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(j!=i && nums[j]==nums[i])
                    return true;
            }
        }
        return false;

    }
};