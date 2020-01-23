#define ll int
#define pb push_back
ll bs(ll beg,ll end,vector<int>& nums, ll ans, ll target)
{
    if(beg>end)
        return -1;
    ll mid=beg+(end-beg)/2;
    if(nums[mid]+ans==target)
        return mid;
    if(nums[mid]+ans>target)
        return bs(beg,mid-1,nums,ans,target);
    else
        return bs(mid+1,end,nums,ans,target);
}
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<ll> >s;
        vector<vector<ll> >ans;
        for(ll i=0;i<n;i++)
        {
            for(ll j=i+1;j<n;j++)
            {
                for(ll k=j+1;k<n;k++)
                {
                    vector<ll>vec;
                    ll temp=bs(k+1,n-1,nums,nums[i]+nums[j]+nums[k],target);
                    if(temp==-1)
                        continue;
                    vec.pb(nums[i]);
                    vec.pb(nums[j]);
                    vec.pb(nums[k]);
                    vec.pb(nums[temp]);
                    if(s.find(vec)!=s.end())
                        continue;
                    ans.pb(vec);
                    s.insert(vec);
                }
            }
        }
        return ans;
    }
};