class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int r01=0,r02=0;
        int r11=0,r12=0;
        for(int i=nums.size()-2;i>=0;i--){
            int t1=max(nums[i]+r01,r02);
            r01=r02;
            r02=t1;
            int t2=max(nums[i+1]+r11,r12);
            r11=r12;
            r12=t2;
        }
        return max(r02,r12);
    }
};
