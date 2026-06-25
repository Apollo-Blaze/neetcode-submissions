class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> dup;
        for(auto x:triplets){
            if(x[0]>target[0] || x[1]>target[1] || x[2]>target[2]) continue;
            dup.push_back(x);
        }
        int a=0,b=0,c=0;
        for(auto x: dup){
            a=max(a,x[0]);
            b=max(b,x[1]);
            c=max(c,x[2]);
        }
        return(a==target[0] && b==target[1] && c==target[2])?true:false;
    }
};
