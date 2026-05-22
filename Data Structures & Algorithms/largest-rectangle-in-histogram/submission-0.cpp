class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> st;
        int maxv = 0;
        for(int i = 0; i < heights.size(); i++){
            while(st.size() && heights[i] < heights[st.back()]){
                int idx = st.back(); st.pop_back();
                int width = st.empty() ? i : i - st.back() - 1;
                maxv = max(maxv, heights[idx] * width);
            }
            st.push_back(i);
        }
        while(st.size()){
            int idx = st.back(); st.pop_back();
            int width = st.empty() ? (int)heights.size() : (int)heights.size() - st.back() - 1;
            maxv = max(maxv, heights[idx] * width);
        }
        return maxv;
    }
};