class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> check;
        for(auto x:nums){
            if(check.find(x)!=check.end()) return x;
            else{
                check.insert(x);
            }
        }
    }
};
