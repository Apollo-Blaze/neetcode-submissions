class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    bool pali(string s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1]) return false;
        }
        return true;
    }
    void dfs(int i,string& s){
        if(i==s.size()){
            res.push_back(path);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(pali(s.substr(i,j-i+1))){
                path.push_back(s.substr(i,j-i+1));
                dfs(j+1,s);
                path.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        dfs(0,s);
        return res;
    }
};
