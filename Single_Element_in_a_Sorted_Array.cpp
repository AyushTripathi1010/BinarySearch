//  Leetcode Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        //     xor solutiion in O(n) space and O(1) time.
        /*     int xors = 0;
                int n = nums.size();
               for(int i =0 ; i <n; i++)
                {
                  xors = xors^nums[i];
                }

                return xors;
          }*/

        /*  binary search solution in log(n) time and O(1) space
            koi inution aisa nhi hai  , bas observe krna hai apne aap pata chal jayega.

       EG:  the original array should have been like this:
               [1,1,2,2,3,3,4,4,8,8] , where every element is occuring twice.
       index:  [0,1,2,3,4,5,6,7,8,9]

        after rmoval of one element : all will shift one index back.

        now observation begins:
        given input : [1,1,2,2,3,3,4,8,8], here 4 is occuring once.
        index       : [0,1,2,3,4,5,6,7,8]

        if i take out mid it comes out to be :(0+8)/2 = 4,  ie, nums[4] = 3.
        here mid is even index, as in the original array, then compare it with nums[mid+1]
        if nums[mid] == nums[mid+1], that means, the left part is same as orignial array,
        so move lo = mid+2, +2 because the nums[mid+1] is same element as current.

        Note: any element that is occuring once in nums array, its index will be always even.
        and in original array: if element occurs in pair then one is present at even index,
        and the other pair element occurs at even index+1 = odd index.
        */

        int lo = 0, high = n - 1;
        int ans = 0;
        while (lo < high)
        {
            int mid = (lo + high) >> 1;

            // means the left part has all elements in pair
            if (mid % 2 == 0 && (nums[mid] == nums[mid + 1]))
                lo = mid + 2;
            // means the left part as all elements in pair, including it.
            else if (mid % 2 != 0 && (nums[mid] == nums[mid - 1]))
                lo = mid + 1;
            // means this the possible ans.
            else
                high = mid;
        }

        return nums[high];
    }
};