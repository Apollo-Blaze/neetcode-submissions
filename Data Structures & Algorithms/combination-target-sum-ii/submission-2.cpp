class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates,int i,vector<int> cur, int total,int target){
            if(total==target){
                res.push_back(cur);
                return;
            }
            if(total>target || i==candidates.size()){
                return;
            }
            cur.push_back(candidates[i]);
            dfs(candidates,i+1,cur,total+candidates[i],target);
            cur.pop_back();
            i++;
            while(i<candidates.size() && candidates[i]==candidates[i-1]) i++;
            dfs(candidates,i,cur,total,target);
        }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates,0,vector<int>(),0,target);
        return res;
    }
};
