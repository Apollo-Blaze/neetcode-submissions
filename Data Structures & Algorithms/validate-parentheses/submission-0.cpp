class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> braces={{'[',']'},{'{','}'},{'(',')'}};
        vector<char> st;
        for(int i=0;i<s.size();i++){
            if(braces.count(s[i]))
                st.push_back(s[i]);
            else{
                if(st.empty()) return false; 
                char val=st.back();
                st.pop_back();
                if(s[i]!=braces[val]) return false;
            }
        }
        return st.empty();
    }
};
