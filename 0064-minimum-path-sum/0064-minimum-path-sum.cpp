class Solution {
    
    int minsum(int row,int col,vector<vector<int>>&grid,int m,int n, vector<vector<int>>& dp)
    {
        if(row>=m||col>=n) return 1e9;
        
        if(row==m-1&&col==n-1)return grid[row][col];
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        int right = 1e9;
        int down=1e9;
        
        if(col<n)
        {
            right=grid[row][col]+minsum(row,col+1,grid,m,n,dp);
        }
        
        if(row<m)
        {
            down=grid[row][col]+minsum(row+1,col,grid,m,n,dp);
        }
        
        return dp[row][col]= min(right,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m= grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return minsum(0,0,grid,m,n,dp);
    }
};