GFG LINK: https://practice.geeksforgeeks.org/problems/0a7c7f1089932257071f9fa076f25d353f91e0fd/1


#include <bits/stdc++.h>
using namespace std;
 

class Solution{
    public:


      // INTUITION: is simple, just, here we have to find maximum sweetness, that is 
      //  minimum, so the geek ahould have minimum sweetness.
      //  so we will aplly simple binary search and if the targestSweetness,
      //  that we selected is meets the condition such that k becomes zero,
      //  so this cab e our answer but since we want maximum, so we will 
      //  move the lo  pointer to mid+1.






    bool isPossible(int targetSweetness , vector<int> &sweetness, int N, int K)
    {
        int sum = 0;
        for(int i = 0 ;i < N ; i++)
        {     
               if(K== 0) return true;
            if(sum + sweetness[i] >= targetSweetness)
            {
                K--;
                sum = 0;
            }
            else
            {
                sum+= sweetness[i];
            }
        }
        
        return K<=0;
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    
    
           int lo = *min_element(sweetness.begin(), sweetness.end());
           
           int high = accumulate(sweetness.begin(), sweetness.end(), 0);
           int ans=-1;
           while(lo <= high)
           {
               int mid = lo + (high-lo)/2;
               
               if(isPossible(mid , sweetness, N, K+1))
               {
                   ans = mid;
                   lo = mid+1;
               }
               else
               high = mid-1;
           }
           
           return ans;
    }
};


	int main() {

	    int t;
	    cin >> t;
	    while (t--) {
	        int n, k;
	        cin >> n >> k;
	        vector<int> sweetness(n);
	        for (int i = 0; i < n; i++) {
	            cin >> sweetness[i];
	        }
	          Solution ob;
	          int res=ob.maxSweetness(sweetness, n, k);
	        cout << res << endl;
	    }
	}