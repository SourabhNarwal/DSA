//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    if(size==1)
    return false;
    
    sort(arr,arr+size);
    
        int first=0;
        int second=1;
        
        
        while(second<size&&first<size-1)
        {   int number=arr[second]-arr[first];
           
            if(number==n&&first!=second)
            {
                return true;
            }
            else if(n>number)
             second++;
            
            else
             first++;
        }
        
    
    return false;
}