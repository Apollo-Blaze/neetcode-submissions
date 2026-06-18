class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> h1;
        vector<int> h2;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size()-1;i++){
            h1.push_back(nums[i]);
            h2.push_back(nums[i+1]);
        }
        int r01=0,r02=0;
        int r11=0,r12=0;
        for(int i=h1.size()-1;i>=0;i--){
            int t1=max(h1[i]+r01,r02);
            r01=r02;
            r02=t1;
            int t2=max(h2[i]+r11,r12);
            r11=r12;
            r12=t2;
        }
        return max(r02,r12);
    }
};
