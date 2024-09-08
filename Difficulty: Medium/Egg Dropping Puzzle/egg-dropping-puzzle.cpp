//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
     int eggDropHelper(int n, int k, vector<vector<int>>& memo) 
    {
        if (k == 0 || k == 1) return k;
        if (n == 1) return k;
        
        if (memo[n][k] != -1) return memo[n][k];
        
        int minAttempts = INT_MAX;
        
        for (int x = 1; x <= k; x++) {
            int attempts = 1 + max(eggDropHelper(n - 1, x - 1, memo), eggDropHelper(n, k - x, memo));
            minAttempts = min(minAttempts, attempts);
        }
        
        return memo[n][k] = minAttempts;
    }
    
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
        
        for(int i=0;i<=n;i++)
        {
            memo[i][0]=0;
            memo[i][1]=1;
        }
        for(int i=0;i<=k;i++)
        {
            memo[1][i]=i;
        }
        
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= k; j++) {
                memo[i][j] = INT_MAX;
                for (int x = 1; x <= j; x++) {
                    
                    int attempts = 1 + max(memo[i-1][x-1], memo[i][j-x]);
                    
                    memo[i][j] = min(memo[i][j], attempts);
                }
            }
        }
        
        return memo[n][k];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends