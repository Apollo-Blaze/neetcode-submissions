class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<float> fleet;
        vector<pair<int,int>> cars;
        for(int i=0; i<position.size(); i++)
            cars.push_back({position[i], speed[i]});
        sort(cars.begin(), cars.end());
        for(int i=position.size()-1;i>=0;i--){
            float val=(float)(target-cars[i].first)/cars[i].second;
            if(fleet.size() && fleet.back()>=val){
                continue;
            }
            else fleet.push_back(val);
        }
        return fleet.size();
    }
};
