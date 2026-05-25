class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int maxfreq=0;
        int maxc=0;
        int l=0,r=0;
        while(r<s.size()){
            freq[s[r]]++;
            maxfreq=max(maxfreq,freq[s[r]]);
            while((r-l+1-maxfreq)>k){
                freq[s[l]]--;
                l++;
            }
            maxc=max(maxc,r-l+1);
            r++;
        }
        return maxc;
    }
};
