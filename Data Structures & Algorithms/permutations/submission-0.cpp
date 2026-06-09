class Solution {
public:
    vector<vector<int>> p(vector<int>& nums,int i) {
        if(i==nums.size()) return {{}};
        vector<vector<int>> l=p(nums,i+1);
        vector<vector<int>> res;
        for(auto x:l){
            for(int j=0;j<x.size()+1;j++){
                vector<int> temp=x;
                temp.insert(temp.begin()+j,nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        return p(nums,0);
    }
};
