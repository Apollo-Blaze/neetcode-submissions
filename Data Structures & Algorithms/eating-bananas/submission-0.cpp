class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxv=0;
        for(auto x:piles) maxv=max(maxv,x);
        int l=1,r=maxv;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            int time=0;
            for(auto x:piles){
                time+=ceil((double)x/mid);
            }
            if(time <= h) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};
