// Leetcode Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public: 

    //  INTTUITION : simple hai yaar , hame ye to pata hai ki rotated sorted array me
    //  ek index aisa hoga jiske left part khud me sorted hoga and index ke right vala
    //  part khud me sorted hoga.
    //  and ek baar hame bas ye pata chal jaaye ki target kis side vale sorted array me 
    //  present hai to ham normal binary search se dhoondh lenge.
    //  to pivot hamara hoga array ka minimum element kyuki, usi ka left side sorted hoga,
    //  and right side sorted hoga.
    int  findpivot(vector<int> &nums , int n)
    {
        int lo = 0, high = n-1;

         while(lo < high)
         {
             int mid= (lo + high)>>1;
             
             if(nums[mid]  > nums[high])
             {
                 lo = mid+1;
             }
             else
             {
                 high = mid;
             }
         }
         return high;
    }

     int bs(vector<int> &nums , int target , int lo , int high)
     {
          while(lo <= high)
          {
              int mid = (lo + high)>>1;

              if(nums[mid] == target) return mid;

              if(target > nums[mid])
              {
                  lo = mid+1;
              }
              else
              high = mid-1;
          }

          return -1;
     }
    int search(vector<int>& nums, int target) {
           

           int n = nums.size();
           
           int lo = 0 , high  = n-1;
            
            int pivot = findpivot(nums  , n);
        
             

            int idx = bs(nums , target , 0 , pivot-1);

             if(idx == -1)
             {
               idx =   bs(nums, target , pivot , high);
             }

             return idx;


    }
};