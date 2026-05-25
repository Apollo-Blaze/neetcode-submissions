class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ss;
        int l=0,r=0;
        int maxc=0;
        int count=0;
        while(r<s.size() && l<s.size()){
            if(!ss.count(s[r])){
                ss.insert(s[r]);
                r++;
            }
            else{
                maxc=max(maxc,(r-l));
                while(ss.count(s[r])){
                    ss.erase(s[l]);
                    l++;
                }
                ss.insert(s[r]);
                r++;
            }
        }
        return max(maxc, r-l);
    }
};
