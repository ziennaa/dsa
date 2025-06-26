class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool found = true;
        int low=0;
        int high=n-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<=m; j++){
                int mid = (low+high)/2;
                if(target<matrix[i][mid]){
                    high = mid-1;
                }else if(target>matrix[i][mid]){
                    low = mid+1;
                }else{
                    return true;
                }
            }
        }
        return false;
    }
};

// wrong
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool found = true;
        for(int i=0; i<n; i++){
            int low=0;
            int high=m-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(target<matrix[i][mid]){
                    high = mid-1;
                }else if(target>matrix[i][mid]){
                    low = mid+1;
                }else{
                    return true;
                }
            }
        }
        return false;
    }
};
