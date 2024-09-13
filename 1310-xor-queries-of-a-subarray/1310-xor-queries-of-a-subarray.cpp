class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n1=arr.size();
        int n2=queries.size();
        
        vector<int> res;
        
        for(auto v :queries)
        {
            int left=v[0];
            int right=v[1];
            if(left==right)
            {
              res.push_back(arr[left]);
            }
            else
            {
                int xo=arr[left]^arr[left+1];
                for(int i=left+2;i<=right;i++)
                {
                    xo=xo^arr[i];
                }
                res.push_back(xo);
            }
        }
        return res;
    }
};