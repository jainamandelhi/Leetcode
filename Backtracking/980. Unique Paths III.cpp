class Solution {
public:
    int ans = 0;
    int vis[25][25] = {0};
    int n , m;
    vector<pair<int,int> >v = {{0,1}, {0,-1}, {-1,0}, {1,0}};
    bool check(int x, int y, vector<vector<int> >&grid)
    {
        return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && (grid[x][y] != -1);
    }
    void dfs(int x, int y, vector<vector<int> >&grid, int total)
    {
        if(grid[x][y] == 2)
        {
            if(total == -1)
                ans++;
            return;
        }
        for(int i = 0; i < 4; i++)
        {
            
            if(check(x+v[i].first, y+v[i].second, grid))
            {
                vis[x+v[i].first][y+v[i].second] = 1;
                dfs(x+v[i].first, y+v[i].second, grid, total-1);
                vis[x+v[i].first][y+v[i].second] = 0;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int total = 0;
        int rx = -1, ry = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0 ; j < m; j++)
            {
                total += (grid[i][j] == 0);
                if(grid[i][j] == 1)
                {
                    rx = i;
                    ry = j;
                }
            }
        }
        vis[rx][ry] = 1;
        dfs(rx, ry, grid, total);
        return ans;
    }
};