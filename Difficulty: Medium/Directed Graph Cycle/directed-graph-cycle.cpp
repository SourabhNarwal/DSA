//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
 
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
       
       int indegree[V]={0};
        
        for(int i=0;i<V;i++)
        {
            for(auto j:adj[i])
            {
                indegree[j]+=1;
            }
        }
       
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        // if(q.size()==0&&V>0)
        //   return false;
           
           vector<int>topo;
           while(!q.empty())
           {
             int node=q.front();
             q.pop();
             topo.push_back(node);
             for(auto i: adj[node])
             {
                 indegree[i]-=1;
                 if(indegree[i]==0)
                 {
                     q.push(i);
                 }
             }
           }
           
           if(topo.size()<V||topo.size()>V)
           return true;
           
           return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends