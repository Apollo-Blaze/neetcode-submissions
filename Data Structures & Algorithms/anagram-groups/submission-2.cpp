class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> finder;
        for(auto x:strs){
            string news = x;        
            sort(news.begin(), news.end());  
            if(finder.find(news)!=finder.end()) finder[news].push_back(x);
            else finder[news]={x};
        }
        vector<vector<string>> result;
        for(auto y: finder){
            result.push_back(y.second);
        }
        return result;
    }
};
