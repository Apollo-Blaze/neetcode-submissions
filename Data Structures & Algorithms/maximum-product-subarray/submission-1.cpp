class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        for(int i:nums){
            res=max(res,i);
        }
        int cmax=1,cmin=1;
        for(auto x:nums){
            if(x==0){
                cmax=1;
                cmin=1;
                continue;
            }
            int t= x*cmax;
            cmax=max({t,x*cmin,x});
            cmin=min({t,x*cmin,x});
            res=max(res,cmax);
        }
        return res;
    }
};
