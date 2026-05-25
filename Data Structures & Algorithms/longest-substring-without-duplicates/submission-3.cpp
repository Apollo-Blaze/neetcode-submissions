class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ss;
        int l=0, maxc=0;
        for(int r=0; r<s.size(); r++){
            while(ss.count(s[r])){
                ss.erase(s[l]);
                l++;
            }
            ss.insert(s[r]);
            maxc = max(maxc, r-l+1);
        }
        return maxc;
    }
};