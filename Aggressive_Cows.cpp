// GFG Link: https://practice.geeksforgeeks.org/problems/aggressive-cows/1

#include <bits/stdc++.h>
using namespace std;


class Solution {
    //  INTUITION : simple hai yaar , yaha hame bola gaya hai ki har cows ko ek stall pe 
    // rakhna hai and hame distance between stalls given hai, to hame har cow ko iss tarah
    // se stall pe rakhna hai, ki distance between kisi bhi 2 cows maximum ho
    
    // and kyuki cows ko alag alag tareeko se rakha jaa sakta hai to, har permuation ka 
    // apna ek maximum distance aayega , and unn saare maximums me hame minimum bata hai
    
    // approach: kyuki hame ye to pata ki distance maximum raknhi hai , to ham first cow,
    // ko sabse pehle stall pe rakh denge , greedily soche to, 
    // and ek aur chiz ye hai ki hame stalls ko sort krna hoga, taaki ham 
    // cows ko optimally maximum distance pe rakh paaye.
    //  and agar ham saar cows ko nhi rakh paate hai kisi target_distance pe to
    // distance kam krna padega.
    
public:
     bool isPossible(int target_distance , vector<int> &stalls , int n , int k)
     {
         int dist = stalls[0];
         int cows = 1;
         for(int i = 1 ; i <  n ; i++)
         {
             if(cows == k) return true;
             
             if(stalls[i] - dist >= target_distance)
             {
                 cows++;
                 dist = stalls[i];
             }
         }
         
         return cows >= k;
         
     }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
          
          sort(stalls.begin() , stalls.end());
        
           int lo = 1 , high = 1e9;
           int ans =0;
           while(lo <= high)
           {
               int mid = lo + (high-lo)/2;
               
               if(isPossible(mid , stalls , n , k))
               {
                   ans = mid;
                   lo = mid+1;
               }
               else
               {
                   high = mid-1;   
               }
           }
           
           return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends