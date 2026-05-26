class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        unordered_map<char,int> check, window;
        for(auto x: s1) check[x]++;
        int l=0;
        for(int r=0; r<s2.size(); r++){
            window[s2[r]]++;
            if((r-l+1) > s1.size()) {
                window[s2[l]]--;
                if(window[s2[l]] == 0) window.erase(s2[l]);
                l++;
            }
            if(window == check) return true;
        }
        return false;
    }
};
