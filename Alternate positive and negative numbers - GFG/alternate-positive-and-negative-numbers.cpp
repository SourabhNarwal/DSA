//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	   if(n<2)
	   {return;}
	   
	    int temparr[n];
	   
	    
	    int i=0;
	    int j=0;
	    int k=0;
	    
	    while(i<n&&j<n&&k<n)
	    {
	        if(arr[i]>=0)
	        {
	            if(arr[j]<0)
	            {
	               temparr[k]=arr[i];
	               k=k+1;
	               temparr[k]=arr[j];
	               k++;
	               i++;j++;
	            }
	            else
	            {j++;}
	        }
	        else
	        {i++;}
	    }
	    
	    while(i<n)
	    {  if(arr[i]>=0)
	        {temparr[k]=arr[i];
	         k++;}
	         i++;
	    }
	    while(j<n)
	    {  if(arr[j]<0)
	       { temparr[k]=arr[j];
	          k++;}
	        j++;
	    }
	    i=0;k=0;
	    while(k<n)
	    {
	        arr[i]=temparr[k];
	        i++;k++;
	    }
	    //free(temparr);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends