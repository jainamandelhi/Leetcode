class Solution {
public:
    vector<vector<int> >v;
    vector<int>ans;
    int flag = 0;
    void dfs(int i,int j,set<int>&s,int a,int b)
    {
        if(flag)
            return;
        s.insert(i);
        for(int k = 0; k < v[i].size(); k++)
        {
            if(flag)
                return;
            if(v[i][k] == j)
                continue;
            if(i == a && v[i][k] == b)
                continue;
            if(i == b && v[i][k] == a)
                continue;
            if(s.find(v[i][k]) != s.end())
            {
                flag = 1;
                return;
            }
            dfs(v[i][k],i,s,a,b);
            if(flag)
                return;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        v = vector<vector<int> >(1002);
        for(int i = 0; i < n; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i = n-1; i >= 0; i--)
        {
            flag = 0;
            set<int>s;
            dfs(1,1,s,edges[i][0],edges[i][1]);
            if(flag)
                continue;
            else if(s.size() == n)
            {
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                break;
            }
        }
        return ans;
    }
};