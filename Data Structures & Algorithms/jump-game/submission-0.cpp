class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumps=0;
        int i=0;
        for(;i<nums.size()-1;i++){
            jumps=max(nums[i],jumps);
            if(jumps==0) break;
            jumps--;
        }
        return i==(nums.size()-1)?true:false;
    }
};
