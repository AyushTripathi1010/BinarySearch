// LeetCode Link : https://leetcode.com/problems/longest-increasing-subsequence/

// INTUITION : here to find the length of longest increasing subsequence we are using 
//  binary search, so we all insert the 1st element in our temp array, ad start
// form 1st index, and if nums[i] > temp.back() , then we insert it in our temp
// arry, otherwise we find the first elemnt in our temp which is greater than
// or equal to nums[i], and at that index we update the value.

// NOTE: the temp array's size gives us the length of longest increasing
//  subsequence, however it does not represent the elements of lis correctly.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
          
          int n = nums.size();

          vector<int> temp ; 
          temp.push_back(nums[0]);

          for(int i =1 ; i < n ; i++)
          {
                if(nums[i] > temp.back())
                {
                    temp.push_back(nums[i]);
                }
                else
                {
                   int ind = lower_bound(temp.begin() , temp.end() , nums[i]) -temp.begin();
                   temp[ind] = nums[i];
                }
          }

          return temp.size();
    }
};