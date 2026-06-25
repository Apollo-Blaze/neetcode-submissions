class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gassum=0;
        int costsum=0;
        for(int i=0;i<gas.size();i++){
            gassum+=gas[i];
            costsum+=cost[i];
        }
        if(gassum<costsum) return -1;
        int total=0;
        int index=0;
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
            if(total<0){
                total=0;
                index=i+1;
            }
        }
        return index;
    }
};
