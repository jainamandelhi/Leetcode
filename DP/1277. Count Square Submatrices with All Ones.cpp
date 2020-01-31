class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    if(i-1>=0 && j-1>=0 && mat[i-1][j]>0 && mat[i][j-1]>0
                      && mat[i-1][j-1]>0)
                    {
                        int temp=min(mat[i-1][j],mat[i][j-1]);
                        temp=min(temp,mat[i-1][j-1]);
                        mat[i][j]=temp+1;
                    }
                    
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans+=mat[i][j];
            }
        }
        return ans;
    }
};