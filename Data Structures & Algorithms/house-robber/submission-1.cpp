class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()>2){
            for(int i=nums.size()-3;i>=0;i--){
                nums[i]=max(nums[i+2]+nums[i],nums[i+1]);
            }
        }
        if(nums.size()==1) return nums[0];
        return max(nums[0],nums[1]);
    }
};
