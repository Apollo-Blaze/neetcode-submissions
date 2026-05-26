class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int> need;
        for(auto x: t) need[x]++;
        int required = need.size();
        unordered_map<char,int> window;
        int formed = 0;
        int minLen = INT_MAX;
        int ansL = 0;
        for(int r=0, l=0; r<s.size(); r++)
        {
            window[s[r]]++;
            if(need[s[r]] && need[s[r]]==window[s[r]])formed++;
            while(formed==required){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    ansL = l;
                }
                    window[s[l]]--;
                    if(need[s[l]] && need[s[l]]>window[s[l]])formed--;
                    l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(ansL, minLen);
    }
};
