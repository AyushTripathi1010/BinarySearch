// LeetCode Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous

// INTUITION : The intuition caan be build from the brute force technique, here we have an array and we want to make 
// it coninous array in minimum operations, i.e:
// 1.) All elements in nums are unique.
// 2.) The difference between the maximum element and the minimum element in nums equals nums.length - 1.

// From above 2 conditions we can observe that we have to make an  consecutive array, which can be jumbled up as well but 
// containe all the elements from mini to (mini + nums.size() - 1); 
// Eg: [1,2,3,4] or [2,1,4,3] both are continous array, because the difference between maximum and minimum element is
// nums.size() - 1 and all elements are in range of [mini, mini + nums.size() - 1].

// What we can do is first sort the nums array and to avoid duplicates we can store elements in set
// and then copy them in temp array.
// Every element will be considered L i.e Lower Bound and R = L + n -1. as upper bound.
// Then check which all elements are in this range, so instead of traversing the whole array again and again
// for every L elemnt, we have that is why stored elements in temp in sorted array. SO that we can directly
// find the upper bound of element R.

// Eg: [2,7,8,6] , n = 4
// considering L = 2 , then R = 2 + 4-1 = 5 , i.e [2,5] => operations equals to elements which are not in this range, 
// 2 in Range, 7 not in Range, 8 not in Range, 6 not in Range, : ans = 3.
// Now consider L= 7, then R = 7+ 4-1 = 10, i.e[7,10]
// 2 not in range, 7 in range, 8 in range, 6 not in range, ans = 2.
// Similarly consider L = 6 , then R = 6 + 4-1, i.e [6,9]
// 2 not in Range, 7 in Range, 8, in Range, 6 in Range, ans = 1,
// so minimum ans = 1, i.e only one element is out of range i.e 2.if we consider 6 as our minimum

// We can sort the array as [2,6,7,8], and then find upper bound for R = 9, where L = 6
// so upper_bound will point to 4th index, which means that elements that are in range are j-i
// where j = upper_bound index and i is index of element L = 6.

class Solution {
public:
    int minOperations(vector<int>& nums) {
         int n = nums.size();
         set<int>s;
         for(int &elem : nums) s.insert(elem);
         vector<int> temp(s.begin() , s.end());
         int ans = INT_MAX;
         for(int i =0 ; i < temp.size() ; i++)
         {
             int L = temp[i];
             int R = temp[i] + n - 1;

             int j = upper_bound(temp.begin() , temp.end() , R)- temp.begin();

             int within_Range = j-i;
             int out_of_Range = n - within_Range;

             ans = min(ans, out_of_Range);
         }

         return ans;
    }
};