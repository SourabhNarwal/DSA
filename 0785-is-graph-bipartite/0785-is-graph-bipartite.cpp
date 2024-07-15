class Solution {
    bool checkcomponent(int curr,vector<int>& setno,vector<vector<int>>& graph)
    {
        queue<pair<int,int>> q;
        q.push({curr,0});
        
        while(!q.empty())
        {
            int node=q.front().first;
            int set=q.front().second;
            int nextset=abs(set-1);
        
            for(int adjnode:graph[node])
            {
              if(setno[adjnode]==set)
              {   
                  return false;
              }
                if(setno[adjnode]==-1)
                {   
                    q.push({adjnode,nextset});
                    }
            }
            setno[node]=set;
            q.pop();
        }
        return true;
        
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int n=graph.size();
        vector<int> setno (n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(setno[i]==-1)
            {
                if(!checkcomponent(i,setno,graph))
                {
                    return false;
                }
            }
        }
        return true;
    }
};