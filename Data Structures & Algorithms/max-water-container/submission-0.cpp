class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxw=0;
        int l=0, r=heights.size()-1;
        int temp=0;
        while(l<r){
            temp=(r-l)*(min(heights[l],heights[r]));
            maxw=max(temp,maxw);
            if(heights[l]<heights[r]) l++;
            else if(heights[l]>heights[r]) r--;
            else{
                l++; r--;
            }
        }
        return maxw;
    }
};
