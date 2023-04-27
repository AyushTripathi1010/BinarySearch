// Leetcode Link : https://leetcode.com/problems/binary-search/description/

//  Intuition : Simple hai yaar, we know that elements are in sorted fashion so , 
//              we can simply find the middle element and check whether the 
//              element lies to the left half or to the right half, and keep
//               in shifting until we get the target element, else return -1.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        
        int start = 0;
        int end = nums.size()-1 ;
        
        while(start<=end)
        {
            int mid = (start + end)/2;
            if(nums[mid]==target)   return mid;  
            else if(nums[mid] <target)   start = mid+1;
            
            else   end = mid-1;          
        }
        return -1;
    }
};
