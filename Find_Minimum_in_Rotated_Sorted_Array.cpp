// Leetcode Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    // Intuition : simple hai yaar , jo bhi mid element aaye usko last element se 
    //  compare krlo agar nums[mid] > last element se then minimum lies in right side,
    //  agar chhota hai to minimum lies in left side

    //  eg : 3 6 8 9 12 1 2 , here mid = 9 which is greater than 2 so minium lies to right.

    //  2nd eg : 9 12 1 2 3 6 8 , here mid = 2 , which is smaller than 8 so minimum lies,
    //  to the left side.

    int findMin(vector<int>& nums) {
            
            int n = nums.size();

            int lo = 0 , high= n-1;

            while(lo < high)
            {
                int mid = (lo + high)>>1;

                if(nums[mid] > nums[high])
                {
                      lo = mid+1;
                }
                else
                {
                     high = mid;
                }
            }

            return nums[high];

    }
};