class Solution {
public:
    int jump(vector<int>& nums) {
        int step=0;
        int r=0;
        int l=0;
        int maxStep=0;
        while(r<nums.size()-1){
            for(int i=l;i<=r;i++){
                maxStep=max(maxStep,i+nums[i]);
            }
            l=r+1;
            r=maxStep;
            step++;
        }
        
        return step;
    }
};
