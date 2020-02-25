#define ll int
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<ll> >arr(n,vector<ll>(n));
        for(ll k=0;k<n;k++)
        {
            for(ll i=0;i<n;i++)
            {
                ll j=i+k;
                if(j>=n)
                    break;
                if(k<2)
                {
                    if(s[i]==s[j])
                        arr[i][j]++;
                }
                else
                {
                    if(s[i]==s[j] && arr[i+1][j-1])
                        arr[i][j]++;
                }
            }
        }
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
                ans+=arr[i][j];
        }
        return ans;
    }
};