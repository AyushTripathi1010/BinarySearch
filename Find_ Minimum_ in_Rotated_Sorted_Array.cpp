//  Leetocode Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:

//     Intuition : simple hai yaar , bas 1 D array me change krdo by formula
//     1D me jo index aayaa hai , uska equivalent in matrix hoga : 
    //    row = mid/col
    //    col = mid%col
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

        int r = matrix.size();
        int c = matrix[0].size();

        int lo = 0 , high = r*c-1;

        while(lo <= high)
        {
            int mid = (lo + high)>>1;
              
              if(matrix[mid/c][mid%c] == target) return true;

             if(matrix[mid/c][mid%c]  < target )
             {    
                  lo = mid+1;
             }
             else
             {
                 high = mid-1;
             }
        }

        return false;
    }
};