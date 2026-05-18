class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right(nums.size());
        vector<int> product;
        for(int i=0;i<nums.size();i++){
            if(i==0)left.push_back(1);
            else left.push_back(nums[i-1]*left[i-1]);
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1)right[i]=1;
            else right[i]=nums[i+1]*right[i+1];
        }
        for(int i=0;i<nums.size();i++){
            product.push_back(left[i]*right[i]);
        }
        return product;
    }
};
