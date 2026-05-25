class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=prices.back();
        int maxprofit=0;
        for(int i=prices.size()-1;i>=0;i--){
            if(prices[i]>sell){
                sell=prices[i];
            }
            else{
                maxprofit = max(maxprofit, sell - prices[i]);
            }
        }
        return maxprofit;
    }
};
