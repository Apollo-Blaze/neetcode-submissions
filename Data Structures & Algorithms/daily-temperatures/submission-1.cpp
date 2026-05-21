class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> st;
        vector<int> days(temperatures.size(), 0);
        
        for(int i=0; i<temperatures.size(); i++){
            while(st.size() && temperatures[i] > temperatures[st.back()]){
                int id = st.back();
                st.pop_back();
                days[id] = i - id;
            }
            st.push_back(i);
        }
        return days;
    }
};