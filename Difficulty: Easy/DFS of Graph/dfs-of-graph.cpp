//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void dfs(int v,int curr, vector<int> adj[],vector<int>&ans,  
              unordered_map<int,bool>& visited)
              {
                  if(v==0)
                  return;
                  
                  ans.push_back(curr);
                  visited[curr]=true;
                  for(auto i:adj[curr])
                  {
                      if(!visited[i])
                      {
                          dfs(v-1,i,adj,ans,visited);
                      }
                  }
                  
              }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        
        vector<int>ans;
        unordered_map<int,bool>visited;
        dfs(v,0,adj,ans,visited);
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends