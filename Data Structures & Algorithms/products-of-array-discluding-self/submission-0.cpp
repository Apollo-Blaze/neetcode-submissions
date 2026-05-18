class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total=1;
        vector<int> out;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i!=j) total*=nums[j];
            }
            out.push_back(total);
            total=1;
        }
        return out;
    }
};
