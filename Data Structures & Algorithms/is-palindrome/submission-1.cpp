class Solution {
public:
    bool isPalindrome(string s) {
        string pal="";
        for(auto x: s){
            if(isalnum(x)) pal+=tolower(x); 
        }
        for(int i=0;i<pal.size()/2;i++){
            if(pal[i]!=pal[pal.size()-1-i]) return false;
        }
        return true;
    }
};
