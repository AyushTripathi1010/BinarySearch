class Solution {
public:
    
    // Note: the intuition of sorting is that we will
    // get minimum differene from starting index itself
    // and we can easily skip the element if it alreay used
    //  in a pair.
    //  Here we have to minimize the maximum difference, 
    // with such count pairs equal to  p.

    bool isPossible(int target_diff , vector<int> &nums , int &p)
    {
         int count = 0;
        for(int  i = 1 ; i < nums.size() ; )
        {   
            //  Since my maximum difference limit is target_diff , so i 
            // will count only those pairs whose absolute difference is less 
            //  than target_diff.  
            if(abs(nums[i] - nums[i-1]) <= target_diff)
            {
                count++;
                i+=2;
            }
            else
            i++;
        }

        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
           
           int n = nums.size();

        //    unordered_map<int, int> m;
         sort(nums.begin() , nums.end());
           int maxi = INT_MIN , mini = INT_MAX;
           


           int lo = 0 , high = nums[n-1] - nums[0];
             int ans = 0;
           while(lo <= high)
           {
               int mid = lo + (high - lo)/2;

               if(isPossible(mid , nums , p))
               {
                   ans = mid;
                   high = mid -1;
               }
               else
               lo = mid+1;

           } 

           return ans;
    }
};