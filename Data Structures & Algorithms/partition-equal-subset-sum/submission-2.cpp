class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(auto x:nums){
            total+=x;
        }
        if(total%2!=0)return false;
        total/=2;
        unordered_set<int> dp;
        dp.insert(0);
        for(int i=nums.size()-1;i>=0;i--){
                cout<<"The current val is:"<<nums[i]<<"\n";
                vector<int> adder;
                for(auto x:dp){
                    cout<<"The current dp val is:"<<x<<"\n";
                    if((nums[i]+x)==total){
                        cout<<nums[i]+x;
                        return true;
                    }
                    if(dp.find(nums[i]+x)==dp.end()){
                        adder.push_back(nums[i]+x);
                    }
                }
                for(auto x:adder){
                    dp.insert(x);
                }
        }
        return false;
    }
};
