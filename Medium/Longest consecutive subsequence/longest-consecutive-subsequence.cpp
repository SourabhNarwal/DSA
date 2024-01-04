//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      if(n==1)
      return 1;
      
      set<int> sortedstorage;
      for(int i=0;i<n;i++)
      {   
         sortedstorage.insert(arr[i]);
      }
      
      int count=1;
      int maxcount=1;
      int i=1;
      auto prev=sortedstorage.begin();
      sortedstorage.erase(*prev);
      //cout<<*prev<<endl;
      auto next=sortedstorage.begin();
      //cout<<*next<<endl;
      while(!sortedstorage.empty())
      {  
          if(*prev== *next-1)
          {
              count=count+1;
              if(count>maxcount)
              {
                  maxcount=count;// 38  37  45 
              }  //         38 45
          }
          else
          {count=1;}
          
          prev=next;
          sortedstorage.erase(*next);
          next=sortedstorage.begin();
      }
      return maxcount;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends