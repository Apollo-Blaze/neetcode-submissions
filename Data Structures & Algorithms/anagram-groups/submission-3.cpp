class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> finder;
        for(auto x : strs){
            int count[26] = {0};
            for(char c : x){
                count[c - 'a']++;
            }
            string key = "";
            for(int i = 0; i < 26; i++){
                key += to_string(count[i]) + ",";
            }
            finder[key].push_back(x);
        }
        vector<vector<string>> result;
        for(auto y : finder){
            result.push_back(y.second);
        }
        return result;
    }
};