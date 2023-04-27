// Leetcode Link : https://leetcode.com/problems/binary-search/description/

// INTUITION: Simple hau yaar, same code as iterative, jaise hi target mil jata hai
//            just return it.
class Solution {
public: 
    int bs(vector<int> &nums , int target, int lo, int high)
    {   
        if(lo <= high)
        {    
            int mid = (lo + high)>>1;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) return bs(nums , target , mid+1 , high);
            else
           return bs(nums , target , lo , mid-1);
        }
        
        return -1;
    }

    int search(vector<int>& nums, int target) {
            
            int n = nums.size();
           return bs(nums , target, 0 , n-1 );
    }
};