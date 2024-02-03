//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
       if(arr.size()<3)
       {   swap(arr[0],arr[arr.size()-1]);
           return arr;
       }
       int size=arr.size();
       int i=size-2;
       int swappossible=0;
       while(i>=0)
       {
           if(arr[i]<arr[i+1])
           {
               swappossible=1;break;
             
           }
           i--;
       }
       if(swappossible==1)
       {   
           sort(arr.begin() +i+1,arr.end());
           for(int j=i+1;j<size;j++)
           {    
               if(arr[i]<arr[j]){
                   swap(arr[i],arr[j]);
                   
                   return arr;
               }
           }
       }    
      sort(arr.begin(),arr.end());
       return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends