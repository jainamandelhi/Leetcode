class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int> >q;
        q.push(make_pair(0,0));
        vector<vector<int> >vis(n,vector<int>(m));
        vis[0][0] = 1;
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i == n-1 && j == m-1)
                return true;
            int a = grid[i][j];
            if(a == 1)
            {
                if(j-1 >= 0 && vis[i][j-1] == 0)
                {
                    if(grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6)
                    {
                        vis[i][j-1] = 1;
                        q.push(make_pair(i,j-1));
                    }
                }
                if(j+1 < m && vis[i][j+1] == 0)
                {
                    if(grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5)
                    {
                        vis[i][j+1] = 1;
                        q.push(make_pair(i,j+1));
                    }
                }
            }
            else if(a == 2)
            {
                if(i-1 >= 0 && vis[i-1][j] == 0)
                {
                    if(grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)
                    {
                        vis[i-1][j] = 1;
                        q.push(make_pair(i-1,j));
                    }
                }
                if(i+1 < n && vis[i+1][j] == 0)
                {
                    if(grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6)
                    {
                        vis[i+1][j] = 1;
                        q.push(make_pair(i+1,j));
                    }
                }
            }
            else if(a == 3)
            {
                if(j-1 >= 0 && vis[i][j-1] == 0)
                {
                    if(grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6)
                    {
                        vis[i][j-1] = 1;
                        q.push(make_pair(i,j-1));
                    }
                }
                if(i+1 < n && vis[i+1][j] == 0)
                {
                    if(grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6)
                    {
                        vis[i+1][j] = 1;
                        q.push(make_pair(i+1,j));
                    }
                }
            }
            else if(a == 4)
            {
                if(j+1 < m && vis[i][j+1] == 0)
                {
                    if(grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5)
                    {
                        vis[i][j+1] = 1;
                        q.push(make_pair(i,j+1));
                    }
                }
                if(i+1 < n && vis[i+1][j] == 0)
                {
                    if(grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6)
                    {
                        vis[i+1][j] = 1;
                        q.push(make_pair(i+1,j));
                    }
                }
            }
            else if(a == 5)
            {
                if(i-1 >= 0 && vis[i-1][j] == 0)
                {
                    if(grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)
                    {
                        vis[i-1][j] = 1;
                        q.push(make_pair(i-1,j));
                    }
                }
                if(j-1 >= 0 && vis[i][j-1] == 0)
                {
                    if(grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6)
                    {
                        vis[i][j-1] = 1;
                        q.push(make_pair(i,j-1));
                    }
                }
            }
            else if(a == 6)
            {
                if(i-1 >= 0 && vis[i-1][j] == 0)
                {
                    if(grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)
                    {
                        vis[i-1][j] = 1;
                        q.push(make_pair(i-1,j));
                    }
                }
                if(j+1 < m && vis[i][j+1] == 0)
                {
                    if(grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5)
                    {
                        vis[i][j+1] = 1;
                        q.push(make_pair(i,j+1));
                    }
                }
            }
        }
        return false;
    }
};