class Solution {
       vector<int> adj[3000];
    void dfs(int index,stack<int>&s,unordered_map<int,bool>&visited)
    {
        visited[index]=true;
        
        for(auto i:adj[index])
        {
            if(!visited[i])
            {
                dfs(i,s,visited);
            }
        }
        s.push(index);
    }
    
    bool checkforcycle(stack<int>&s,int size)
    {
        unordered_map<int,int> pos;
        int index=0;
        while(!s.empty())
        {
            int x=s.top();
            s.pop();
            pos[x]=index++;
        }
        
        for(int parent=0;parent<size;parent++)
        {
            for(auto child:adj[parent])
            {
                if(pos[child]<=pos[parent])
                {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,bool> visited;
      
        for(auto i:prerequisites)
        {
           adj[i[1]].push_back(i[0]);
        }
       
        stack<int> s;
        
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                dfs(i,s,visited);
            }
        }
        
        return !(checkforcycle(s, numCourses));
        
        return true;
    }
};