#define ll int
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        ll n=A.size();
        vector<vector<ll> >v(n,vector<ll>(n));
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(i==0)
                {
                    v[i][j]=A[i][j];
                    continue;
                }
                ll a=A[i][j]+v[i-1][j];
                if(j-1>=0)
                {
                    a=min(a,A[i][j]+v[i-1][j-1]);
                }
                if(j+1<n)
                {
                    a=min(a,A[i][j]+v[i-1][j+1]);
                }
                v[i][j]=a;
            }
        }
        ll ans=INT_MAX;
        for(ll i=0;i<n;i++)
            ans=min(ans,v[n-1][i]);
        return ans;
    }
};