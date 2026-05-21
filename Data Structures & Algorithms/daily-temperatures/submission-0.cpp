class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        vector<int> days(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            if(res.size()){
                if (temperatures[i]>temperatures[res.back()]){
                    while(res.size() && temperatures[i]>temperatures[res.back()]){
                        int id=res.back();
                        days[id]=i-id;
                        res.pop_back();
                    }
                    res.push_back(i);
                }
                else res.push_back(i);
            }
            else{
                res.push_back(i);
            }
        }
        return days;
    }
};
