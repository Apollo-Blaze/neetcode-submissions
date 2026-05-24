class Solution {
public:
    int binary_search(vector<int>& nums,int l, int r, int target){
            int mid;
            while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int l=0,r=nums.size()-1;
        int mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]>nums[r]) l=mid+1;
            else r=mid;
        }
        int pivot = l;
        int res = binary_search(nums, 0, pivot-1, target);
        if(res >= 0) return res;
        return binary_search(nums, pivot, nums.size()-1, target);
    }
};
