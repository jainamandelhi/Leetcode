class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();
        int ans = 0;
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        for(int p = 0; p < n; p++)
        {
            for(int qq = 0; qq < m; qq++)
            {
                if(vis[p][qq] || grid[p][qq] == '0')
                    continue;
                ans++;
                vis[p][qq] = 1;
                queue<pair<int,int> >q;
                q.push(make_pair(p,qq));
                while(!q.empty())
                {
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();
                    if(i+1 < n && grid[i+1][j] == '1' && !vis[i+1][j]){
                        q.push(make_pair(i+1,j));
                        vis[i+1][j] = 1;
                    }
                    if(i-1 >= 0 && grid[i-1][j] == '1' && !vis[i-1][j]){
                        q.push(make_pair(i-1,j));
                        vis[i-1][j] = 1;
                    }
                    if(j+1 < m && grid[i][j+1] == '1' && !vis[i][j+1]){
                        q.push(make_pair(i,j+1));
                        vis[i][j+1] = 1;
                    }
                    if(j-1 >= 0 && grid[i][j-1] == '1' && !vis[i][j-1]){
                        q.push(make_pair(i,j-1));
                        vis[i][j-1] = 1;
                    }
                }
            }
        }
        return ans;
    }
};