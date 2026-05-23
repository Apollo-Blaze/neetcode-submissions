class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size()-1;
        int col=matrix[0].size()-1;
        int l=0,r=row;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(matrix[mid][col]>=target) r=mid-1;
            else l=mid+1;
        }
        int rows = l;
        if(rows > row) return false;
        l=0; r=col;
        int temp = r;
        while(l<=r){
            mid=l+(r-l)/2;
            if(matrix[rows][mid]>=target) r=mid-1;
            else l=mid+1;
        }
        int temp2=r;
        return matrix[rows][l]==target;

    }
};
