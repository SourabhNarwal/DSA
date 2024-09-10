//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   bool palindrome(string &s)
   {
       int size=s.size();
       for(int i=0;i<size;i++)
       {
           if(s[i]!=s[size-i-1])return false;
       }
       return true;
   }

   int parts(int start,int size,string &str,vector<int>& dp)
   {
       if(start>=size)return 0;
       
       if(dp[start]!=-1)return dp[start];
       
       int mini=INT_MAX;
       for(int i=start;i<size;i++)
       {
           int p=INT_MAX;
           string s=str.substr(start,i-start+1);
           if(palindrome(s))
           {
               p=1+parts(i+1,size,str,dp);
               mini=min(mini,p);
           }
           
       }
       return dp[start]= mini;
   }

    int palindromicPartition(string str)
    {
        // code here
       
        int size=str.size();
         vector<int> dp(size+1,-1);
        return parts(0,size,str,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends