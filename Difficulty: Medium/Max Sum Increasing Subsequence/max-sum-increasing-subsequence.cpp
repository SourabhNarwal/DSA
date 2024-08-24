//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
    int seqsum(int curri,int lasti,int arr[],int n,vector<vector<int>>&dp)
    {
        if(curri>=n+1)
        return 0;
     
            if(dp[curri][lasti]!=-1) return dp[curri][lasti];
      
        int taken=INT_MIN;
        
        int not_taken= seqsum(curri+1,lasti,arr,n,dp);
        
        if(lasti!=0)
        {
            if(arr[lasti-1]<arr[curri-1])
            {
                taken=arr[curri-1]+seqsum(curri+1,curri,arr,n,dp);
            }
        }
        else
        {
            taken=arr[curri-1]+seqsum(curri+1,curri,arr,n,dp);
        }
        
      dp[curri][lasti]= max(taken,not_taken);
         return dp[curri][lasti];
    }
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+1,vector<int> (n,-1));
	    seqsum(1,0,arr,n,dp);
	    return dp[1][0];
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
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends