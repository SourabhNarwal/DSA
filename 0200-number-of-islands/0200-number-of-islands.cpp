class Solution {
    void dfs(int rows,int cols,int row,int col,vector<vector<char>>& grid,vector<vector<int>>& visited)
    {  
        visited[row][col]=1;
       
        //check right
        if(col+1<cols )
        {  if(visited[row][col+1]==0&&
           grid[row][col+1]=='1')
        {dfs(rows,cols,row,col+1,grid,visited);}
        }
        //check down
        if(row+1<rows&&grid[row+1][col]=='1')
        {
            if(visited[row+1][col]==0)
            {dfs(rows,cols,row+1,col,grid,visited);}
        }
         //check left
        if(col-1>=0&&grid[row][col-1]=='1')
        {   if(visited[row][col-1]==0)
             {dfs(rows,cols,row,col-1,grid,visited);}
        }
        //check up
        if(row-1>=0&&grid[row-1][col]=='1')
        {if(visited[row-1][col]==0)
        {dfs(rows,cols,row-1,col,grid,visited);
        }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> visited (301,vector<int>(301,0));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
              if(grid[i][j]=='1'&&visited[i][j]==0)
              {  
                  dfs(rows,cols,i,j,grid,visited);
                  count++;
              }
                  
            }
        }
        return count;
    }
};