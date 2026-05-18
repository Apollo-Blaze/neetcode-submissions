class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check;
        int maxc=0;
        for(auto x: nums) check.insert(x);
        for(auto x: nums){
            int temp=1;
            if(check.find(x-1)==check.end()){
                int flag=1;
                while(flag){
                    if(check.find(x+1)!=check.end()) temp++;
                    else flag=0;
                    x++;
                }
            }
            if(temp>maxc) maxc=temp;
        }
        return maxc;
    }
};
