class Solution {
public:
    void backtrack(int idx, int currentSum, vector<int>& path,
                   vector<int>& candidates, int target,
                   vector<vector<int>>& result){
        if(currentSum == target){
            result.push_back(path);
            return;
        }
        if(currentSum > target) return;
        
        for(int i = idx; i < candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            backtrack(i, currentSum + candidates[i], path, candidates, target, result);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(0, 0, path, candidates, target, result);
        return result;
    }
};