// GFG LINK: https://practice.geeksforgeeks.org/problems/rotation4723/1
class Solution{
public:	
    //  INTUITION : question vahi hai yaar , jisme minimum element in rotated 
    // sorted array nikalna tha, bas is case me uss minimum element ka index
    //   nikaalna hai utne hi time vo rotate hua hai.
	int findKRotation(int arr[], int n) {
	    // code here
	     
	     int lo = 0 , high = n-1;
	     int idx =0;
	     while(lo< high)
	     {
	         int mid = (lo + high)>>1;
	         
	         if(arr[mid] > arr[high])
	         {
	             lo = mid+1;
	         }
	         else
	         {
	            high = mid;   
	         }
	     }
	     
	     return high;
	}

};