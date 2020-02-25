#define ll int
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        ll n=days.size();
        set<ll>m;
        for(ll i=0;i<n;i++)
            m.insert(days[i]);
        vector<int>ans(days[n-1]+1);
        for(int i=0;i<ans.size()-1;i++)
        {
            ll a=ans[i],b=ans[i],c=ans[i];
            if(m.find(i+1)!=m.end())
            {
                if(i+1-1>=1)
                    a=ans[i+1-1]+costs[0];
                else
                    a=costs[0];
                if(i+1-7>=1)
                    b=ans[i+1-7]+costs[1];
                else
                    b=costs[1];
                if(i+1-30>=1)
                    c=ans[i+1-30]+costs[2];
                else
                    c=costs[2];
            }
            ans[i+1]=min(a,min(b,c));
        }
        return ans[ans.size()-1];
    }
};