class Solution {
public:
    vector<string> res;
    unordered_map<char,string> digittostr={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    void dfs(string& digits,int i,string curr){
        if(curr.size()==digits.size()){
            res.push_back(curr);
            return;
        }
        string t=digittostr[digits[i]];
        for(auto c:t){
            dfs(digits,i+1,curr+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits!="") dfs(digits,0,"");
        return res;
    }
};
