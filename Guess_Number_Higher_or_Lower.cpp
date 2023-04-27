// Leetcode Link: https://leetcode.com/problems/guess-number-higher-or-lower/description/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
    // INTUITION: simple hai yaar, simple binary search, and guess is the predefined function,
    // given in the question which return 3 possible values:
    // -1: Your guess is higher than the number I picked (i.e. num > pick).
    // 1: Your guess is lower than the number I picked (i.e. num < pick).
    // 0: your guess is equal to the number I picked (i.e. num == pick).
    // public:
    int guessNumber(int n) {
           
           int lo = 1 , high = n;

           while(lo<= high)
           {
               int guess_no = lo + (high-lo)/2;

               int val = guess(guess_no);
               if(val == 0) return guess_no;
               
               if(val == -1) high = guess_no-1;
               else
               lo = guess_no+1;
           }
           return 0;
    }
};