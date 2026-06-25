class Solution {
public:
    vector<int> partitionLabels(string s) {
        int l=0,r=0;
        int maxr=0;
        vector<int> res;
        unordered_map<char,pair<int,int>> hm;
        for(int i=0;i<s.size();i++){
            if(hm.find(s[i])==hm.end()){
                hm[s[i]].first=i;
                hm[s[i]].second=i;
            }
            else{
                hm[s[i]].second=i;
            }
        }
        while(r<s.size()){
            if(r>maxr){
                res.push_back(r-l);
                l=r;
            }
            maxr=max(maxr,hm[s[r]].second);
            r++;
        }
        if(maxr==s.size()-1) res.push_back(r-l);
        return res;
    }
};
