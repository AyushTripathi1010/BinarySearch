// LeetCode Link : https://leetcode.com/problems/split-array-largest-sum/
class Solution {
public:
     bool isPossibleSum(vector<int> nums , int k ,int limit_sum)
     {
          int sum=0;
           int cnt=1;
          for(int i =0 ;i< nums.size() ; i++)
          {
               if(sum + nums[i] <= limit_sum) sum+=nums[i];
               else
               {
                   cnt++;
                   sum = nums[i];
               }

               if(cnt > k) return false;
          }
          return true;
     }
    int splitArray(vector<int>& nums, int k) {
        
        int lo =0 , high=0;

        for(auto i: nums) {
            lo = max(lo , i);
            high+= i;
        }

        while(lo < high)
        {
            int mid = (lo+high)/2;

            if(isPossibleSum(nums , k , mid))
            {
                  high = mid;
            }
            else
            lo = mid+1;
        }

        return lo;
    }
};