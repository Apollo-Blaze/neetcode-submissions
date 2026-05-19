class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        while(true){
            int sum = numbers[l] + numbers[r];  // compute once
            if(sum < target) l++;
            else if(sum > target) r--;
            else return {l+1, r+1};
        }
        
    }
};
