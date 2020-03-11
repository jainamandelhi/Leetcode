class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int> >vis(grid.size(),vector<int>(grid[0].size()));
        queue<tuple<int,int,int> >q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_tuple(i,j,0));
                    vis[i][j]=1;
                }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            int i=get<0>(q.front());
            int j=get<1>(q.front());
            int c=get<2>(q.front());
            q.pop();
            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1)
            {
                q.push(make_tuple(i-1,j,c+1));
                vis[i-1][j]=1;
                ans=max(ans,c+1);
            }
            if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1)
            {
                q.push(make_tuple(i,j-1,c+1));
                vis[i][j-1]=1;
                ans=max(ans,c+1);
            }
            if(i+1<grid.size() && !vis[i+1][j] && grid[i+1][j]==1)
            {
                q.push(make_tuple(i+1,j,c+1));
                vis[i+1][j]=1;
                ans=max(ans,c+1);
            }
            if(j+1<grid[0].size() && !vis[i][j+1] && grid[i][j+1]==1)
            {
                q.push(make_tuple(i,j+1,c+1));
                vis[i][j+1]=1;
                ans=max(ans,c+1);
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                    return -1;
            }
        }
        return ans;
    }
};