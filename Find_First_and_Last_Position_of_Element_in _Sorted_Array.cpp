// Leetcode Link:  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

// INTUITION: Simple hai yaar, hame target ka first occurence and last occurence batanca hai,
//  to FirstOccurence nikalne ke liye : if  nums[mid] >= target ,then this could be my ans,
//  so store it and nove to left.
//  LastOccurence nikalne ke liye : if nums[mid] <= target, then this can be my answer but 
//  move towards right;
class Solution {
public:
     int LastOccurence( int lo , int high , int target , vector<int> &nums  )
     {         int ub = -1;
             while(lo <= high)
             {
                 int mid = (lo+high)/2;
                 
                 if(nums[mid] <= target)
                 {    
                      if(target == nums[mid]) ub = mid;
                      lo = mid+1;
                 }
                 else
                 {   
                     high = mid -1;
                 }
             }

             return ub;
     }
     int FirstOccurence( int lo , int high , int target , vector<int> &nums )
     {         int lb = -1;
             while(lo <= high)
             {
                 int mid = (lo+high)/2;
                   
                   if(nums[mid] < target)
                   {
                       lo = mid+1;
                   }
                   else
                   {
                       if(nums[mid] == target) lb = mid;

                       high = mid-1;
                   }
             }

             return lb;
     }
    vector<int> searchRange(vector<int>& nums, int target) {
             
             int n = nums.size();


            int ub = LastOccurence(0 , n-1 , target , nums);
            int lb = FirstOccurence(0 , n-1 , target , nums);

            return {lb , ub};

    }
};