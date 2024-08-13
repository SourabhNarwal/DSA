class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.size();
        int size2=text2.size();
        vector<vector<int>> seq(size1+1,vector<int>(size2+1,0));
        
        for(int i=1;i<=size1;i++)
        {
            for(int j=1;j<=size2;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                   seq[i][j]=seq[i-1][j-1]+1;
                }
                else{
                    if(seq[i-1][j]>seq[i][j-1])
                    {
                       seq[i][j]=seq[i-1][j];  
                    }
                    else{
                         seq[i][j]=seq[i][j-1]; 
                    }
                }
            }
        }
        return seq[size1][size2];
    }
};