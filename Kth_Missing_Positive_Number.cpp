// Leetcode Link: https://leetcode.com/problems/kth-missing-positive-number/description/
class Solution
{

    //  INTUITION: it is just ibservation:
    // Eg: Let the original array be: [1,2,3,4,5,6,7,8,9,10,11]
    // index be: [0,1,2,3,4,5,6,7,8,9 ,10]

    //  The input array given to us is: [2,3,4,7,11]
    //  index  is: [0,1,2,3, 4]

    // if we calculate the mid for the input array: 0+4)/2 = 2 => nums[2]= 4.
    // how to calculate kitne numbers missing hai before 4:
    //  4 ko original array me 3rd pe hai, but input array me 2nd index hai, means :
    //  kitne_number_missing_hai =
    //     mid element orignal array pe kis index pe tha - input array me kis index pe hai.
    //     =          3  - mid.

    // here we have to find 5th missing positive integer.

public:
    int findKthPositive(vector<int> &arr, int k)
    {

        int n = arr.size();

        int lo = 0, high = n - 1;

        while (lo <= high)
        {
            int mid = (lo + high) >> 1;

            int kitne_numbers_missing_hai = (arr[mid] - 1) - (mid);
            //  means we will ahve to move ahead as we don't have sufficent integers.
            if (kitne_numbers_missing_hai < k)
            {
                lo = mid + 1;
            }
            else
                high = mid - 1;
        }

        return lo + k;
    }
};