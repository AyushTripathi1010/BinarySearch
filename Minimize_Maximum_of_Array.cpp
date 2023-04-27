// Leetcode Link: https://leetcode.com/problems/minimize-maximum-of-array/
class Solution
{
public:
    // INTUITION : smiple hai yaar , that the main catch here is about the first element
    //  of array as it can't be decreased but only be increased,
    //   so nums[0] is the smallest maximum value we can acheive , then we are using the 
    // concept of buffer which is storing the difference by which we can 
    // decrease the next element , and even after decreasing it is smaller than 
    // the expected_max it means it is not possible to acheive this maximum so 
    // look for the greater maximum.
    int isPossible(vector<int> &nums, int n, int target)
    {
        vector<long long> arr(begin(nums), end(nums));
        long long buffer = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > target)
                return false;

            buffer = target - arr[i];
            arr[i + 1] -= buffer;
        }

        return arr[n - 1] <= target;
    }
    int minimizeArrayValue(vector<int> &nums)
    {

        int n = nums.size();

        int max_elem = *max_element(begin(nums), end(nums));

        int lo = nums[0], high = max_elem;
        int ans = 0;
        while (lo <= high)
        {
            int mid = (lo + high) >> 1;

            if (isPossible(nums, n, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                lo = mid + 1;
        }

        return ans;
    }
};