class Solution {
public:
    unordered_map<int,int> dp;
    int dfs(int i,string s){
        if(dp.find(i)!=dp.end()) return dp[i];
        if(i == s.size()) return 1;
        if(s[i]=='0')return 0;
        int res=dfs(i+1,s);
        if(i+1 < s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1]>='0' && s[i+1]<='6'))) res+=dfs(i+2,s);
        dp[i]=res;
        return res;
    }
    int numDecodings(string s) {
        return dfs(0,s);
    }
};
