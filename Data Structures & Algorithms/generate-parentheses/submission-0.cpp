class Solution {
public:
    vector<string> res;
    void dfs(int n,string s,int o, int c){
        if(o == n && c == n){
            res.push_back(s);
            return;
        }
        if(o < n)
            dfs(n, s + "(", o+1, c);
        if(c < o)
            dfs(n, s + ")", o, c+1);
    }
    vector<string> generateParenthesis(int n) {
        dfs(n,"",0,0);
        return res;
    }
};
