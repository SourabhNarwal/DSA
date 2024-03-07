//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    if(n==3)
	    {
	        if(arr[0]+arr[1]+arr[2]<sum)
	          return 1;
	        
	        return 0;
	    }
	    long long count=0;
	    sort(arr,arr+n);
	    for(int i=0;i<n-2;i++)
	    {
	        int j=i+1;
	        int k=n-1;
	        while(j<k)
	        {
	            int currsum=arr[i]+arr[j]+arr[k];
	            if(currsum>=sum)
	            {
	                k--;
	            }
	            else 
	            {
	                count+=k-j;j++;
	            }
	            
	        }
	    }
	    return count;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends