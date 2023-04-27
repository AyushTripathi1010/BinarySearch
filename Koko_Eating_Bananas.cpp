// Leetcode Link: https://leetcode.com/problems/koko-eating-bananas/
class Solution {
public:
        //  INTUITION: kis speed k, se monkey can eat banana  ki saare bananas h ghante me khatham
        // ho jaaye, unme se minium k bataao jo condition satisfy krde, else return -1.
        // i have taken high as maximum element as k cant go beyond it., sunce we minimum k.
        

     bool isPossible(vector<int> &piles , int k , int n , int h )
     {
        
            // checking how much time does it take to complete bananas from a pile if eaten at speed
            //  of k banans/hr.
         for(int i= 0 ; i <n ;i++)
         {    
                if(piles[i]%k == 0) h-= (piles[i]/k);
                else
                {
                    h-= (piles[i]/k + 1);
                }
         }

         return h>=0;
     }
    int minEatingSpeed(vector<int>& piles, int h) {
             
             int n = piles.size();

             int high = *max_element(begin(piles) , end(piles));
                // int high  = 1e9;

             int lo = 1;

              int ans= 0;
             while(lo <= high)
             {
                 long long mid = lo + (high-lo)/2;

                 if(isPossible(piles , mid , n , h))
                 {
                     ans = mid;
                     high = mid-1;
                 }
                 else
                 {
                     lo = mid+1;
                 }
             }

             return ans;
    }
};