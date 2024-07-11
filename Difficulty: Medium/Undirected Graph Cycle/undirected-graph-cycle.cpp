//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool inthiscomponent(int src,unordered_map<int,bool>&visited,vector<int> adj[])
    {
        queue<pair<int,int>>q;
        q.push({src,-1});
        visited[src]=true;
        while(!q.empty())
        {
            auto node=q.front();
            int vertex=node.first;
            
            int parent=node.second;
            for(auto i:adj[vertex])
            {   if(i==parent)
            {
                int nothing;
            }
            else if(visited[i])
            {
                return true;
            }
             else
                {visited[i]=true;
                  q.push({i,vertex});
                }
                
            }
            q.pop();
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool> visited;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
               if( inthiscomponent(i,visited,adj))
               {
                   return true;
               }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends