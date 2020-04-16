class Solution {
public:
    vector<vector<int> >vis;
    int n,m;
    int ans = 0;
    int flag;
    void dfs(int i,int j,vector<vector<int> >&grid)
    {
        vis[i][j] = 1;
        for(int p = i+1; p < n; p++)
        {
            if(grid[p][j] == 1 && vis[p][j] == 0)
            {
                ans++;
                flag = 1;
                dfs(p,j,grid);
            }
        }
        for(int p = i-1; p >= 0; p--)
        {
            if(grid[p][j] == 1 && vis[p][j] == 0)
            {
                ans++;
                flag = 1;
                dfs(p,j,grid);
            }
        }
        for(int q = j+1 ; q < m; q++)
        {
            if(grid[i][q] == 1 && vis[i][q] == 0)
            {
                ans++;
                flag = 1;
                dfs(i,q,grid);
            }
        }
        for(int q = j-1 ; q >= 0; q--)
        {
            if(grid[i][q] == 1 && vis[i][q] == 0)
            {
                ans++;
                flag = 1;
                dfs(i,q,grid);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        vis = vector<vector<int> >(501,vector<int>(501));
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                flag = 0;
                if(vis[i][j] || !grid[i][j])
                    continue;
                dfs(i,j,grid);
                if(flag)
                    ans++;
            } 
        }
        return ans;
    }
};