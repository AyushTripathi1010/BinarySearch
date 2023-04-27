//  Leetcode Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
    //  INTUITION: same as search in rotated sorted array, with distint elements, but here
    // the elements can be repeated, so everything will be same, we will just skip the repeated elements
    //  from start as well as from end everytime.
public:
    int findPivot(vector<int> &nums , int n , int lo , int high)
    {    int ans = 0;
        
         
        while(lo < high)
        {
            // skipping the repeated elements until only one is left.(doing  from start)
             while((lo < high) && (nums[lo]== nums[lo+1])) lo++;
            // skipping the repeated elements until only one is left.(doing from end )
             while((lo < high) &&(nums[high] == nums[high-1]) ) high--; 

            int mid = (lo + high)>>1;

            if(nums[mid] > nums[high])
            {
               lo = mid+1;
            }
            else
            {    
                
                 high  = mid;
            }

        }
        return high;
    }

    bool bs(vector<int> &nums , int n , int lo , int high, int target)
    {
        while(lo<=high)
        {
            int mid = (lo + high)>>1;

            if(nums[mid] == target) return true;

            if(nums[mid] < target) lo  = mid+1;
            else
            high = mid-1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
            
            int n = nums.size();

            int first_ocuurence_of_pivot = findPivot(nums , n , 0 , n-1);
          
        //    if any one of them is true return true else return false.
           return  bs(nums, n , 0 ,first_ocuurence_of_pivot-1, target ) || 
             bs(nums ,n , first_ocuurence_of_pivot , n-1 , target);
           

            
    }
};