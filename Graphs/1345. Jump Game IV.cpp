#define pb push_back
#define mp make_pair
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        map<int,vector<int> >m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]].pb(i);
        }
        vector<int>vis(n);
        queue<pair<int,int> >q;
        q.push(mp(0,0));
        vis[0]=1;
        set<int>s;
        int ans1=INT_MAX;
        while(!q.empty())
        {
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            if(a==n-1)
            {
                return b;
            }
            if(s.find(arr[a])==s.end())
            {
                for(int i=0;i<m[arr[a]].size();i++)
                {
                    s.insert(arr[a]);
                    if(m[arr[a]][i]==a)
                        continue;
                    q.push(mp(m[arr[a]][i],b+1));
                    vis[m[arr[a]][i]]=1;
                }
            }
            if(a-1>=0 && vis[a-1]==0)
            {
                vis[a-1]=1;
                q.push(mp(a-1,b+1));
            }
            if(a+1<n && vis[a+1]==0)
            {
                vis[a+1]=1;
                q.push(mp(a+1,b+1));
            }
        }
        return -1;
    }
};