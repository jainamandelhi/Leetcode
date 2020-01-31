#define ll int
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int> >v1(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j-k>0)
                {
                    v1[i][j]+=v1[i][j-1]+mat[i][j]-mat[i][j-k-1];
                }
                else if(j>0)
                {
                    v1[i][j]+=v1[i][j-1]+mat[i][j];
                }
                else
                {
                    v1[i][j]=mat[i][j];
                }
            }
        }
        vector<vector<int> >v2(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(j+k+1<m)
                {
                    v2[i][j]+=v2[i][j+1]+mat[i][j]-mat[i][j+k+1];
                }
                else if(j<m-1)
                {
                    v2[i][j]+=v2[i][j+1]+mat[i][j];
                }
                else
                {
                    v2[i][j]=mat[i][j];
                }
            }
        }
        vector<vector<ll> >ans(n,vector<ll>(m));
        for(ll j=0;j<m;j++)
        {
            for(ll i=0;i<n;i++)
            {
                for(ll p=0;p<=k;p++)
                {
                    if(i+p<n)
                    {
                        ans[i][j]+=v1[i+p][j]+v2[i+p][j];
                        ans[i][j]-=mat[i+p][j];
                    }
                    if(i-p>=0 && p!=0)
                    {
                        ans[i][j]+=v1[i-p][j]+v2[i-p][j];
                        ans[i][j]-=mat[i-p][j];
                    }
                    
                }
            }
        }
        return ans;
    }
};