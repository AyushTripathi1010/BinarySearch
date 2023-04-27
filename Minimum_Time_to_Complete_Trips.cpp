// Leetcode Link: https://leetcode.com/problems/minimum-time-to-complete-trips/description/
class Solution {
     // INTUITION: yha pe  ham ek time ko pakdege and dekhenge kya uss time pe totalTrips complete
     // krskte hai yaa nhi, agar kr skte hai to ham ise to store karenge hi, and high = mid-1,krdenge
     // taaki iss chhota time ho shahayd koi jo condition satisfy kr rha ho.
     // else lo = mid+1;
     // kisi particular time pe kitne trips complete ho rhi hai vo calculate krne ke liye,
     // simple unitary method lagaayenge:
     // eg : bus which is taking 2 unit time for complete trip.
     //  and if i select time as 9 so how many trips it can complete = 9/2.
public:
     bool isPossible(vector<int> &time , long long target_time , int totalTrips)
     {
            long long ans = 0;
           for(int i =0 ; i <time.size(); i++)
           {
               ans+= (target_time/(time[i]));
           }

           return ans>=(totalTrips);
     }
    long long minimumTime(vector<int>& time, int totalTrips) {
              

              int n = time.size();

              long long lo =  0 , high = 1e14;
                long long ans=0;
              while(lo <= high)
              {
                  long long mid = lo + (high-lo)/2;

                   if(isPossible(time , mid , totalTrips))
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