class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxl(height.size(),0);
        vector<int> maxr(height.size(),0);
        int maxv=0;
        for(int i=1; i<height.size();i++){
            maxv=max(height[i-1],maxv);
            maxl[i]=maxv;
        }
        maxv=0;
        for(int i=height.size()-2; i>=0;i--){
            maxv=max(height[i+1],maxv);
            maxr[i]=maxv;
        }
        int total=0;
        for(int i=0;i<height.size();i++){
            int val=min(maxl[i],maxr[i]);
            if(val>height[i]) total+=val-height[i];
        }
        return total;
    }
};
